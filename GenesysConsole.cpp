/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysShell.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 23 de Maio de 2019, 13:02
 */

#include "GenesysConsole.h"
#include "Simulator.h"
#include "Assign.h"
#include <regex>
#include <fstream>
#include <assert.h>

#include "ProbDistrib.h"

GenesysConsole::GenesysConsole() {
    _commands->setSortFunc([](const ShellCommand* a, const ShellCommand * b) {
	return a->shortname < b->shortname;
    });
    _commands->insert(new ShellCommand("q", "quit", "", "Quit ReGenesys shell. Same as exit.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdQuit)));
    _commands->insert(new ShellCommand("x", "exit", "", "Exit ReGenesys shell. Same as quit.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdQuit)));
    _commands->insert(new ShellCommand("h", "help", "", "Show help for commands.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdHelp)));
    _commands->insert(new ShellCommand("ms", "modelsave", "<filename>", "Save model.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdModelSave)));
    _commands->insert(new ShellCommand("ml", "modelload", "<filename>", "Load Model.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdModelLoad)));
    _commands->insert(new ShellCommand("rf", "readfile", "<filename>", "Read and execute shell command from file.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdScript)));
    _commands->insert(new ShellCommand("v", "version", "", "Show the version.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdVersion)));
    _commands->insert(new ShellCommand("ss", "start", "", "Start simulation.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdStart)));
    _commands->insert(new ShellCommand("mc", "modelcheck", "", "Check model.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdModelCheck)));
    _commands->insert(new ShellCommand("mh", "modelshow", "", "Show model.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdModelShow)));
    _commands->insert(new ShellCommand("ps", "step", "", "step simulation.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdStep)));
    _commands->insert(new ShellCommand("ts", "stop", "", "Stop simulation.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdStop)));
    _commands->insert(new ShellCommand("sr", "showreport", "", "Show simulation report.", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdShowReport)));
    _commands->insert(new ShellCommand("tl", "tracelevel", "<0|1|2|...|7>", "Set the trace level (the bigger the most verbose).", DefineExecuterMember<GenesysConsole>(this, &GenesysConsole::cmdTraceLevel)));
}

GenesysConsole::GenesysConsole(const GenesysConsole& orig) {
}

GenesysConsole::~GenesysConsole() {
}

void GenesysConsole::cmdTraceLevel() {
    Trace("Set trace level");
    try {
	int tlnum = std::stoi(_parameter);
	Util::TraceLevel tl = static_cast<Util::TraceLevel> (tlnum);
	_simulator->getModelManager()->current()->getTraceManager()->setTraceLevel(tl);
    } catch (...) {
	Trace("Error setting trace level");
    }
}

void GenesysConsole::cmdModelCheck() {
    Trace("Check model");
    try {
	_simulator->getModelManager()->current()->checkModel();
    } catch (...) {
	Trace("Error checking model");
    }
}

void GenesysConsole::cmdStart() {
    Trace("Start simulation");
    try {
	_simulator->getModelManager()->current()->getSimulation()->startSimulation();
    } catch (...) {
	Trace("Error starting simulation");
    }
}

void GenesysConsole::cmdStep() {
    Trace("Step simulation");
    try {
	_simulator->getModelManager()->current()->getSimulation()->stepSimulation();
    } catch (...) {
	Trace("Error stepping simulation");
    }
}

void GenesysConsole::cmdStop() {
    Trace("Stop simulation");
    try {
	_simulator->getModelManager()->current()->getSimulation()->stopSimulation();
    } catch (...) {
	Trace("Error stopping simulation");
    }
}

void GenesysConsole::cmdShowReport() {
    Trace("Show report");
    try {
	_simulator->getModelManager()->current()->getSimulation()->getSimulationReporter()->showSimulationStatistics();
    } catch (...) {
	Trace("Error showing reports");
    }
}

void GenesysConsole::cmdHelp() {
    ShellCommand* command;
    Trace("List of commands:");
    Trace(Util::SetW("Short", 6) + Util::SetW("Long", 12) + Util::SetW("Parameters", 15) + "Description");
    for (std::list<ShellCommand*>::iterator it = _commands->getList()->begin(); it != _commands->getList()->end(); it++) {
	//Trace("Unknown command. Type \"-h\" or \"help\" for help on possible commands.");
	command = (*it);
	Trace(Util::SetW(command->shortname, 6) + Util::SetW(command->longname, 12) + Util::SetW(command->parameters, 15) + command->descrition);
    }
}

void GenesysConsole::cmdQuit() {
    Trace("Quiting/Exiting. Goodbye");
    exit(0);
}

void GenesysConsole::cmdVersion() {
    Trace("ReGenesys Shell version 2019.0528");
}

void GenesysConsole::cmdModelLoad() {
    Trace("Model load");
    try {
	std::string filename = _parameter;
	Model* model = new Model(this->_simulator);
	model->loadModel(filename);
    } catch (...) {
	//        _commands
	Trace("   Error loading");
    }
}

void GenesysConsole::cmdModelShow() {
    Trace("Model Show");
    try {
	_simulator->getModelManager()->current()->show();
    } catch (...) {
	//        _commands
	Trace("   Error showing");
    }
}

void GenesysConsole::cmdModelSave() {
    this->_parameter;
}

void GenesysConsole::cmdScript() {
    std::string filename = this->_parameter;
    //List<std::string>* arguments = new List<std::string>();
    std::ifstream commandfile;
    std::string inputText;
    try {
	commandfile.open(filename);
	while (getline(commandfile, inputText)) {
	    this->tryExecuteCommand(inputText, "", "", " ");
	}
	commandfile.close();
    } catch (...) {
	Trace("   Error scripting");
    }
}

void GenesysConsole::Trace(std::string message) {
    std::cout << message << std::endl;
}

void GenesysConsole::run(List<std::string>* commandlineArgs) {
    Trace("ReGenesys Shell is running. Type your command. For help, type the command \"h\" or \"help\".");
    std::string inputText; //, shortPrefix, longPrefix, separator;
    while (true) {
	if (!commandlineArgs->empty()) {
	    inputText = commandlineArgs->front();
	    commandlineArgs->pop_front();
	    tryExecuteCommand(inputText, "-", "--", "=");
	} else {
	    std::cout << _prompt << " ";
	    std::cin >> inputText;
	    tryExecuteCommand(inputText, "", "", " ");

	}
    }
}

void GenesysConsole::tryExecuteCommand(std::string inputText, std::string shortPrefix, std::string longPrefix, std::string separator) {
    std::regex regex{R"([=]+)"}; // split on space R"([\s]+)"
    std::sregex_token_iterator it{inputText.begin(), inputText.end(), regex, -1};
    std::vector<std::string> fields{it,{}};
    std::string typedCommandStr = fields[0];
    if (fields.size() > 1) { // its a comnd and a paramater in the form command=parameter
	assert(fields.size() == 2);
	_parameter = fields[1];
    } else {
	_parameter = "";
    }
    ShellCommand* command;
    bool found;
    std::transform(typedCommandStr.begin(), typedCommandStr.end(), typedCommandStr.begin(), ::tolower);
    if (typedCommandStr.substr(0, 1) != "#") {
	found = false;
	for (std::list<ShellCommand*>::iterator it = _commands->getList()->begin(); it != _commands->getList()->end(); it++) {
	    //Trace("Unknown command. Type \"-h\" or \"help\" for help on possible commands.");
	    command = (*it);
	    if (typedCommandStr == shortPrefix + command->shortname || typedCommandStr == longPrefix + command->longname) {
		command->executer();
		found = true;
		break;
	    }
	}
	if (!found) {
	    Trace("Command \"" + typedCommandStr + "\" not found. Type \"h\" or \"help\" for help.");
	}
    }

}

int GenesysConsole::main(int argc, char** argv) {
    //double res;
    //for (double x = -3.0; x <= 3.0; x += 0.05) {
    //    res = ProbDistrib::tStudent(x, 0, 1, 100);
    //    std::cout << x << ": " << res << std::endl;
    //}
    //return 0;
    List<std::string>* commandlineArgs = new List<std::string>();
    for (unsigned short i = 1; i < argc; i++) {
	std::string arg = argv[i];
	commandlineArgs->insert(arg);
    }
    //commandlineArgs->insert("-rf=temp/script.txt");
    //commandlineArgs->insert("-ml=models/genesysmodel.txt");
    this->run(commandlineArgs);
    return 0;
}