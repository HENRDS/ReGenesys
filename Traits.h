/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Traits.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 19:36
 */

#ifndef TRAITS_H
#define TRAITS_H

// interfaces
#include "Model.h"
#include "Collector_if.h"
#include "Sampler_if.h"
#include "Fitter_if.h"
#include "ModelChecker_if.h"
#include "Parser_if.h"
#include "Statistics_if.h"
#include "Integrator_if.h"
#include "HypothesisTester_if.h"
#include "ModelPersistence_if.h"
#include "GenesysApplication_if.h"
#include "ProcessAnalyser_if.h"
#include "ExperimentDesign_if.h"
#include "SimulationReporter_if.h"

// genesys applications
#include "MyApp.h"
#include "GenesysGUI.h"
#include "GenesysConsole.h"

//  Default implementations
//statistics
#include "CollectorDefaultImpl1.h"
#include "CollectorDatafileDefaultImpl1.h"
#include "StatisticsDefaultImpl1.h"
#include "IntegratorDefaultImpl1.h"
#include "HypothesisTesterDefaultImpl1.h"
#include "SamplerDefaultImpl1.h"
//model
#include "SimulationReporterDefaultImpl1.h"
#include "ModelCheckerDefaultImpl1.h"
#include "ModelPersistenceDefaultImpl1.h"
//parser
#include "parserBisonFlex/ParserDefaultImpl2.h"
//tools
#include "ExperimentDesignDefaultImpl1.h"
#include "ProcessAnalyserDefaultImpl1.h"
#include "FitterDefaultImpl1.h"

template <typename T>
struct Traits {
};

/*
 *  Genesys Application
 */

template <> struct Traits<GenesysApplication_if> {
    //typedef GenesysGUI Application;
    //typedef GenesysConsole Application;
    typedef MyApp Application;
};

/*
 *  Model
 */

template <> struct Traits<Model> {
    static const bool debugged = true;
    static const Util::TraceLevel traceLevel = Util::TraceLevel::blockArrival;// :simulation;
};

template <> struct Traits<ModelPersistence_if> {
    typedef ModelPersistenceDefaultImpl1 Implementation;
};

template <> struct Traits<SimulationReporter_if> {
    typedef SimulationReporterDefaultImpl1 Implementation;
};

template <> struct Traits<ModelComponent> {
    typedef StatisticsDefaultImpl1 StatisticsCollector_StatisticsImplementation;
    typedef CollectorDefaultImpl1 StatisticsCollector_CollectorImplementation;
};

template <> struct Traits<ModelChecker_if> {
    typedef ModelCheckerDefaultImpl1 Implementation;
};

template <> struct Traits<Parser_if> {
    typedef ParserDefaultImpl2 Implementation; //ParserDefaultImpl1
};

/*
 Statistics
 */

template <> struct Traits<Collector_if> {
    typedef CollectorDatafileDefaultImpl1 Implementation;
    //typedef CollectorDatafileDummyImpl Implementation;
    //typedef CollectorDummyImpl ModelImplementation; //TEMP
};

template <> struct Traits<Statistics_if> {
    typedef StatisticsDefaultImpl1 Implementation;
    typedef CollectorDefaultImpl1 CollectorImplementation;
    static constexpr double SignificanceLevel = 0.05;
};

template <> struct Traits<Integrator_if> {
    typedef IntegratorDefaultImpl1 Implementation;
    static constexpr unsigned int MaxIterations = 1e3;
    static constexpr double Precision = 1e-9;
};

template <> struct Traits<Sampler_if> {
    typedef SamplerDefaultImpl1 Implementation;
    typedef SamplerDefaultImpl1::DefaultImpl1RNG_Parameters Parameters;
};

template <> struct Traits<Fitter_if> {
    typedef FitterDefaultImpl1 Implementation;
};

template <> struct Traits<HypothesisTester_if> {
    typedef IntegratorDefaultImpl1 IntegratorImplementation;
    typedef HypothesisTesterDefaultImpl1 Implementation;
};

/*
 * Tools
 */

template <> struct Traits<ExperimentDesign_if> {
    typedef ExperimentDesignDefaultImpl1 Implementation;
};

template <> struct Traits<ProcessAnalyser_if> {
    typedef ProcessAnalyserDefaultImpl1 Implementation;
};

#endif /* TRAITS_H */

