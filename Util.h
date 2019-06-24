/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 13:02
 */

#ifndef UTIL_H
#define UTIL_H

#include <map>
#include <typeinfo>
#include <string>
#include <cctype>
#include <algorithm> 
#include <cctype>
#include <locale>

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}


class Util {
public:
    typedef unsigned long identitifcation;
    typedef unsigned int rank;

    enum class TimeUnit : int {
	picosecond = 1,
	nanosecond = 2,
	microsecond = 3,
	milisecond = 4,
	second = 5,
	minute = 6,
	hour = 7,
	day = 8,
	week = 9
    };

    enum class TraceLevel : int {
	noTraces = 0,
	errors = 1,
	report = 2,
	simulation = 3,
	transferOnly = 4,
	blockArrival = 5,
	blockInternal = 6,
	mostDetailed = 7
    };
private:
    static Util::identitifcation _S_lastId;
    static std::map<std::string, Util::identitifcation> _S_lastIdOfType;
    static std::map<std::string, std::string> _S_TypeOf;

public: // indentation and string
    static unsigned int _S_indentation; // TODO: IS PRIVATE. ITS HERE JUST TO INCLUDE IT AS A WATCH
    static void SetIndent(const unsigned short indent);
    static void IncIndent();
    static void DecIndent();
    static void SepKeyVal(std::string str, std::string *key, std::string *value);
    static std::string Indent();
    static std::string SetW(std::string text, unsigned short width);
    static std::string StrTimeUnit(Util::TimeUnit timeUnit);
public: // identitification
    static Util::identitifcation GenerateNewId();
    static Util::identitifcation GenerateNewIdOfType(std::string objtype);
    static Util::identitifcation GetLastIdOfType(std::string objtype);
    static void ResetIdOfType(std::string objtype);

public: // simulation support
    static double TimeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2);

public: // template implementations

    /*!
     * Return the name of the class used as T.
     */
    template<class T> static std::string TypeOf() {
	std::string name = typeid(T).name();
	std::map<std::string, std::string>::iterator it = _S_TypeOf.find(name);
	if (it != _S_TypeOf.end()) {
	    return(*it).second;
	} else {
	    std::string newname(name);
	    while (std::isdigit(newname[0])) {
		newname.erase(0, 1);
	    }
	    _S_TypeOf.insert(std::pair<std::string, std::string>(name, newname));
	    return newname;
	}
    }

    /*!
     * Every component or element has a unique ID for its class, but not unique for other classes. IDs are generated sequentially for each class.
     */
    template<class T> static Util::identitifcation GenerateNewIdOfType() {
	std::string objtype = Util::TypeOf<T>();
	std::map<std::string, Util::identitifcation>::iterator it = Util::_S_lastIdOfType.find(objtype);
	if (it == Util::_S_lastIdOfType.end()) {
	    // a new one. create the pair
	    Util::_S_lastIdOfType.insert(std::pair<std::string, Util::identitifcation>(objtype, 0));
	    it = Util::_S_lastIdOfType.find(objtype);
	}
	Util::identitifcation next = (*it).second;
	next++;
	(*it).second = next;
	return(*it).second;
    }

private:
    Util();
    Util(const Util& orig);
    virtual ~Util();
};

#endif /* UTIL_H */

