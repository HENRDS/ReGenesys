/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DefineGetterSetter.h
 * Author: rafael.luiz.cancian
 *
 * Created on 5 de Agosto de 2018, 13:52
 */

#ifndef DEFINEGETTERSETTER_H
#define DEFINEGETTERSETTER_H

#include <functional>
#include "Util.h"

typedef std::function<double() > GetterMember;
typedef std::function<void(double) > SetterMember;

// double

template<typename Class>
GetterMember DefineGetterMember(Class * object, double (Class::*function)()) {
    return std::bind(function, object);
}

template<typename Class>
GetterMember DefineGetterMember(Class * object, double (Class::*function)() const) {
    return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(double)) {
    return std::bind(function, object, std::placeholders::_1);
}

// unsigned int

template<typename Class>
GetterMember DefineGetterMember(Class * object, unsigned int (Class::*function)() const) {
    return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(unsigned int)) {
    return std::bind(function, object, std::placeholders::_1);
}

// bool

template<typename Class>
GetterMember DefineGetterMember(Class * object, bool (Class::*function)() const) {
    return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(bool)) {
    return std::bind(function, object, std::placeholders::_1);
}

//std::string

template<typename Class>
GetterMember DefineGetterMember(Class * object, std::string(Class::*function)() const) {
    return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(std::string) const) {
    return std::bind(function, object, std::placeholders::_1);
}

// Util::TimeUnit

template<typename Class>
GetterMember DefineGetterMember(Class * object, Util::TimeUnit(Class::*function)() const) {
    return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(Util::TimeUnit)) {
    return std::bind(function, object, std::placeholders::_1);
}


#endif /* DEFINEGETTERSETTER_H */

