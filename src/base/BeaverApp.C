#include "BeaverApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<BeaverApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

BeaverApp::BeaverApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BeaverApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BeaverApp::associateSyntax(_syntax, _action_factory);
}

BeaverApp::~BeaverApp()
{
}

// External entry point for dynamic application loading
extern "C" void BeaverApp__registerApps() { BeaverApp::registerApps(); }
void
BeaverApp::registerApps()
{
  registerApp(BeaverApp);
}

// External entry point for dynamic object registration
extern "C" void BeaverApp__registerObjects(Factory & factory) { BeaverApp::registerObjects(factory); }
void
BeaverApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BeaverApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BeaverApp::associateSyntax(syntax, action_factory); }
void
BeaverApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
