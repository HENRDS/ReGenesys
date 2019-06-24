#ifndef GENESYSPP_DRIVER_H
# define GENESYSPP_DRIVER_H
# include <string>
# include <map>
# include "GenesysParser.h"
# include "../Model.h"
//# include "../../../ProbDistrib.h"
# include "../Util.h"
# include "../Sampler_if.h"
// Tell Flex the lexer's prototype ...


# define YY_DECL \
  yy::genesyspp_parser::symbol_type yylex (genesyspp_driver& driver)

// # define YY_DECL \
//   yy::genesyspp_parser::symbol_type yylex (semantic_type* yylval, location_type* yylloc, genesyspp_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;
// Conducting the whole scanning and parsing of Calc++.
class genesyspp_driver
{
public:
  genesyspp_driver ();
  genesyspp_driver (Model* model, bool throws);
  virtual ~genesyspp_driver ();

  // Handling the scanner.
  void scan_begin_file ();
  void scan_end_file ();
  void scan_begin_str ();
  void scan_end_str ();

  // Run the parser on file F.
  // Return 0 on success.
  int parse_file (const std::string& f);
  int parse_str (const std::string& str);

  // Error handling.
  void error (const yy::location& l, const std::string& m);
  void error (const std::string& m);

  double getResult();
  void setResult(double value);

  bool getThrowsException();
  void setThrowsException(bool throws);

  void setErrorMessage(std::string message);
  std::string getErrorMessage();

  Model* getModel();
  Sampler_if* getProbs();

  std::string getFile();
  void setFile(std::string f);

  std::string getStrToParse();
  void setStrToParse(std::string str);

private:
  Model* _model;
  Sampler_if* probs;
  double result = 0;
  std::string file;
  std::string str_to_parse;
  bool throwsException = true;
  std::string errorMessage;
};
#endif // ! GENESYSPP_DRIVER_H
