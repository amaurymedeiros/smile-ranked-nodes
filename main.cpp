#include "smile/smile.h"

void CreateNetwork(void) {
    DSL_network theNet;

    int success = theNet.AddNode(DSL_CPT,"Success");

    DSL_idArray someNames;
    someNames.Add("Success");
    someNames.Add("Failure");
    theNet.GetNode(success)->Definition()->SetNumberOfOutcomes(someNames);

    int forecast = theNet.AddNode(DSL_CPT,"Forecast");

    someNames.Flush();
    someNames.Add("Good");
    someNames.Add("Moderate");
    someNames.Add("Poor");
    theNet.GetNode(forecast)->Definition()->SetNumberOfOutcomes(someNames);

    theNet.AddArc(success,forecast);

    DSL_doubleArray theProbs;
    theProbs.SetSize(2);
    theProbs[0] = 0.2;
    theProbs[1] = 0.8;
    theNet.GetNode(success)->Definition()->SetDefinition(theProbs);

    DSL_sysCoordinates theCoordinates (*theNet.GetNode(forecast)->Definition());
    theCoordinates.UncheckedValue() = 0.4;
    theCoordinates.Next();
    theCoordinates.UncheckedValue() = 0.4;
    theCoordinates.Next();
    theCoordinates.UncheckedValue() = 0.2;
    theCoordinates.Next();
    theCoordinates.UncheckedValue() = 0.1;
    theCoordinates.Next();
    theCoordinates.UncheckedValue() = 0.3;
    theCoordinates.Next();
    theCoordinates.UncheckedValue() = 0.6;
    theNet.WriteFile("networks/tutorial.dsl");
};

int main(int argc, char const *argv[])
{
    CreateNetwork();
    return 0;
}