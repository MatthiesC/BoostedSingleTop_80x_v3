#include <iostream>
#include <memory>

#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/CommonModules.h"
#include "UHH2/common/include/CleaningModules.h"
#include "UHH2/common/include/ElectronHists.h"
#include "UHH2/common/include/NSelections.h"
#include "UHH2/BoostedSingleTop/include/BoostedSingleTopSelections.h"
#include "UHH2/BoostedSingleTop/include/BoostedSingleTopHists.h"

#include "UHH2/BoostedSingleTop/include/SingleTopGen_tWch.h"
#include "UHH2/BoostedSingleTop/include/SingleTopGen_tWchHists.h"

using namespace std;
using namespace uhh2;

namespace uhh2examples {

  /** \brief Basic analysis example of an AnalysisModule (formerly 'cycle') in UHH2
   * 
   * This is the central class which calls other AnalysisModules, Hists or Selection classes.
   * This AnalysisModule, in turn, is called (via AnalysisModuleRunner) by SFrame.
   */
  class SingleTopGen_tWchModule: public AnalysisModule {
  public:
    
    explicit SingleTopGen_tWchModule(Context & ctx);
    virtual bool process(Event & event) override;

  private:
    
    //std::unique_ptr<CommonModules> common;
    std::unique_ptr<AnalysisModule> SingleTopGen_tWchProd;
    
    // store the Hists collection as member variables. Again, use unique_ptr to avoid memory leaks.
    std::unique_ptr<Hists> h_singletopgen_twch;
  };


  SingleTopGen_tWchModule::SingleTopGen_tWchModule(Context & ctx){
    // In the constructor, the typical tasks are to initialize the
    // member variables, in particular the AnalysisModules such as
    // CommonModules or some cleaner module, Selections and Hists.
    // But you can do more and e.g. access the configuration, as shown below.
    
    cout << "Hello World from SingleTopGen_tWchModule!" << endl;
    
    // If needed, access the configuration of the module here, e.g.:
    string testvalue = ctx.get("TestKey", "<not set>");
    cout << "TestKey in the configuration was: " << testvalue << endl;
    
    // If running in SFrame, the keys "dataset_version", "dataset_type", "dataset_lumi",
    // and "target_lumi" are set to the according values in the xml file. For CMSSW, these are
    // not set automatically, but can be set in the python config file.
    for(auto & kv : ctx.get_all()){
      cout << " " << kv.first << " = " << kv.second << endl;
    }
    
    // 1. setup other modules. CommonModules and the JetCleaner:
    //common.reset(new CommonModules());
    // TODO: configure common here, e.g. by 
    // calling common->set_*_id or common->disable_*
    //common->disable_jec();
    //common->init(ctx);

    // note that the JetCleaner is only kept for the sake of example;
    // instead of constructing a jetcleaner explicitly,
    // the cleaning can also be achieved with less code via CommonModules with:
    // common->set_jet_id(PtEtaCut(30.0, 2.4));
    // before the 'common->init(ctx)' line.
    
    // 2. set up selections

   // 3. Set up Hists classes:
    SingleTopGen_tWchProd.reset(new SingleTopGen_tWchProducer(ctx, "singletopgen_twch"));
    h_singletopgen_twch.reset(new SingleTopGen_tWchHists(ctx, "nocuts"));
  }


  bool SingleTopGen_tWchModule::process(Event & event) {
    // This is the main procedure, called for each event. Typically,
    // do some pre-processing by calling the modules' process method
    // of the modules constructed in the constructor (1).
    // Then, test whether the event passes some selection and -- if yes --
    // use it to fill the histograms (2).
    // Finally, decide whether or not to keep the event in the output (3);
    // this is controlled by the return value of this method: If it
    // returns true, the event is kept; if it returns false, the event
    // is thrown away.
    
    // cout << "SingleTopGen_tWchModule: Starting to process event (runid, eventid) = (" << event.run << ", " << event.event << "); weight = " << event.weight << endl;
    
    // 1. run all modules other modules.
    //common->process(event);
    SingleTopGen_tWchProd->process(event);

    h_singletopgen_twch->fill(event);
    
    // 3. decide whether or not to keep the current event in the output:
    return true; // keep that on false to not overload the output directory with non-selected MC samples
  }

  // as we want to run the ExampleCycleNew directly with AnalysisModuleRunner,
  // make sure the SingleTopGen_tWchModule is found by class name. This is ensured by this macro:
  UHH2_REGISTER_ANALYSIS_MODULE(SingleTopGen_tWchModule)

}
