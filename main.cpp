#include <iostream>
#include <fstream>
#include "scheduler.h"
#include "server.h"

void simulation (double am, double dm)
{
	Scheduler *sch = new Scheduler ();
	sch->initialize ();

	Server* s = new Server ();
	s->createTraceFile ();

	s->arrivalMean () = am;
	s->departureMean () = dm;
	s->initialize ();

	sch->run ();

	delete s;
	delete sch;
}

void carSimulation (double b_am, double b_dm, double A_dm, double P_dm, double T_dm)
{
	Scheduler *sch = new Scheduler ();
	sch->initialize ();

	Server* BodyShop = new Server ();
	Server* AssemblyLine = new Server ();
	Server* PaintShop = new Server ();
	Server* TestFacility = new Server ();

	BodyShop->createTraceFile ("BodyShop");
	BodyShop->arrivalMean () = b_am;
	BodyShop->departureMean () = b_dm;
	BodyShop->initialize ();

	AssemblyLine->createTraceFile ("AssemblyLine");
	AssemblyLine->arrivalMean () = b_dm;
	AssemblyLine->departureMean () = A_dm;
	AssemblyLine->initialize ();

	PaintShop->createTraceFile ("PaintShop");
	PaintShop->arrivalMean () = A_dm;
	PaintShop->departureMean () = P_dm;
	PaintShop->initialize ();

	TestFacility->createTraceFile ("TestFacility");
	TestFacility->arrivalMean () = P_dm;
	TestFacility->departureMean () = T_dm;
	TestFacility->initialize ();

	sch->run ();

	delete BodyShop;
	delete AssemblyLine;
	delete PaintShop;
	delete TestFacility;
	delete sch;
}


int main ()
{
	for(double a=0.2;a<=1;a+=0.2)
	{
		for(double b=0.2;b<=1;b+=0.2)
		{
			for(double c=0.2;c<=1;c+=0.2)
			{
				for(double d=0.2;d<=1;d+=0.2)
				{
					for(double e=0.2;e<=1;e+=0.2)
					{
						carSimulation (a, b, c, d, e);				
					}
				}
			}
		}
	}
	
    for (double i = 0.2; i < 1.05; i += 0.2)
    {
        //simulation(i, 1);
        carSimulation (i, 1, 1, 1, 1);
    }
    return 0;
}
