/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistence_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 24 de Agosto de 2018, 19:22
 */

#ifndef MODELPERSISTENCE_IF_H
#define MODELPERSISTENCE_IF_H

#include <string>

/*!
 * First and inadequate interface for model persistence. It should use the best pattern for the DAO approach
 */
class ModelPersistence_if {
public:
    // TODO: not a good interface for sure. The Bridge pattern should be a lot better
    virtual bool save(std::string filename) = 0;
    virtual bool load(std::string filename) = 0;
    virtual bool isSaved() = 0;
private:

};

#endif /* MODELPERSISTENCE_IF_H */

