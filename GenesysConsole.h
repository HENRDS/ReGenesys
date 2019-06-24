/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysConsole.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Maio de 2019, 13:02
 */

#ifndef GENESYSCONSOLE_H
#define GENESYSCONSOLE_H

#include "GenesysApplication_if.h"
#include "Simulator.h"
#include "List.h"

class GenesysConsole : public GenesysApplication_if {
private:
    typedef std::function<void() > ExecuterMember;

    template<typename Class>
    ExecuterMember DefineExecuterMember(Class * object, void (Class::*function)()) {
	return std::bind(function, object); //, std::placeholders::_1
    }

    class ShellCommand {
    public:

	ShellCommand(std::string shortname, std::string longname, std::string parameters, std::string descrition, ExecuterMember executer) {
	    this->descrition = descrition;
	    this->longname = longname;
	    this->parameters = parameters;
	    this->shortname = shortname;
	    this->executer = executer;
	}
	std::string shortname;
	std::string longname;
	std::string parameters;
	std::string descrition;
	ExecuterMember executer;
    };
public:
    GenesysConsole();
    GenesysConsole(const GenesysConsole& orig);
    virtual ~GenesysConsole();
public:
    virtual int main(int argc, char** argv);
public: // commands
    void cmdScript();
    void cmdHelp();
    void cmdQuit();
    void cmdModelLoad();
    void cmdModelCheck();
    void cmdStart();
    void cmdStep();
    void cmdStop();
    void cmdShowReport();
    void cmdModelSave();
    void cmdModelShow();
    void cmdVersion();
    void cmdTraceLevel();
private:
    void run(List<std::string>* arguments);
    void Trace(std::string message);
    void tryExecuteCommand(std::string inputText, std::string shortPrefix, std::string longPrefix, std::string separator);
private:
    Simulator* _simulator = new Simulator();
    std::string _parameter;
    List<ShellCommand*>* _commands = new List<ShellCommand*>();
    std::string _prompt = "$ReGenesys> ";
};

#endif /* GENESYSCONSOLE_H */

