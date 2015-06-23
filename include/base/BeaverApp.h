#ifndef BEAVERAPP_H
#define BEAVERAPP_H

#include "MooseApp.h"

class BeaverApp;

template<>
InputParameters validParams<BeaverApp>();

class BeaverApp : public MooseApp
{
public:
  BeaverApp(const std::string & name, InputParameters parameters);
  virtual ~BeaverApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BEAVERAPP_H */
