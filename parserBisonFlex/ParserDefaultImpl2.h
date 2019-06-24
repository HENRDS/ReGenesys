/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserDefaultImpl2.h
 * Author: Joao Ortigara (20180801-20181207) rafael.luiz.cancian (20181208-...(
 *
 * 
 */

#ifndef PARSERDEFAULTIMPL2_H
#define PARSERDEFAULTIMPL2_H

#include <string>
#include "../Parser_if.h"
#include "Genesys++-driver.h"
#include "../Model.h"

class ParserDefaultImpl2 : public Parser_if {
public:
	ParserDefaultImpl2(Model* model);
	ParserDefaultImpl2(Model* model, bool throws);
	ParserDefaultImpl2(const ParserDefaultImpl2& orig);
	virtual ~ParserDefaultImpl2();
public:
	virtual double parse(const std::string expression); // may throw exception
	virtual double parse(const std::string expression, bool* success, std::string* errorMessage);
	virtual std::string* getErrorMessage();
private:
	Model* _model;
	genesyspp_driver _wrapper;
};

#endif /* PARSERDEFAULTIMPL2_H */

