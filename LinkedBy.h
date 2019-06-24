/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedBy.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Agosto de 2018, 07:35
 */

#ifndef LINKEDBYCOMPONENT_H
#define LINKEDBYCOMPONENT_H

class LinkedBy {
public:
    LinkedBy();
    LinkedBy(const LinkedBy& orig);
    virtual ~LinkedBy();
public:
    void addLink();
    void removeLink();
    bool isLinked();
private:
    unsigned int _linkedBy = 0;
};

#endif /* LINKEDBYCOMPONENT_H */

