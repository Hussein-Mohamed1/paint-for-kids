#include "GUI\Input.h"
#include "GUI\Output.h"
#include <string>
#include "CMUgraphicsLib/auxil.h"
//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();



	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click

	//Create Play Mode

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");

	pIn->GetPointClicked(P1.x, P1.y);
	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click second point");
	pIn->GetPointClicked(P2.x, P2.y);
	while (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click second point");
	pIn->GetPointClicked(P2.x, P2.y);
	while (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Square, Normal and Highlighted
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = RED;
	gfxInfo.isFilled = false;
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click center point");
	pIn->GetPointClicked(P1.x, P1.y);
	P2.x = P1.x + 60;
	P2.y = P1.y + 60;
	P1.x -= 60;
	P1.y -= 60;
	while ((!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5)) || (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5)) || (P1.x < 5 || P2.x >= UI.width - 15))
	{
		pOut->PrintMessage("wrong click another center");
		pIn->GetPointClicked(P1.x, P1.y);
		P2.x = P1.x + 60;
		P2.y = P1.y + 60;
		P1.x -= 60;
		P1.y -= 60;
	}
	pOut->DrawRect(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawRect(P1, P2, gfxInfo, true);
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = true;
	pOut->PrintMessage("Drawing a Square ==> filled,  Click center point");
	pIn->GetPointClicked(P1.x, P1.y);
	P2.x = P1.x + 60;
	P2.y = P1.y + 60;
	P1.x -= 60;
	P1.y -= 60;
	while ((!(P1.y > (UI.ToolBarHeight + 5) && P1.y < (UI.height - UI.StatusBarHeight - 5))) || (!(P2.y > (UI.ToolBarHeight + 5) && P2.y < (UI.height - UI.StatusBarHeight - 5))) || (P1.x < 5 || P2.x >= (UI.width - 15)))
	{
		pOut->PrintMessage("wrong click another center");
		pIn->GetPointClicked(P1.x, P1.y);
		P2.x = P1.x + 60;
		P2.y = P1.y + 60;
		P1.x -= 60;
		P1.y -= 60;
	}
	pOut->DrawRect(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawRect(P1, P2, gfxInfo, true);


	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.3.1 - Drawing non-filled triangle
	bool invalid = 1;

	do
	{
		pOut->PrintMessage("Drawing a triangle non filled Click 3 points in drawing area");
		pIn->GetPointClicked(P1.x, P1.y);
		pIn->GetPointClicked(P2.x, P2.y);
		pIn->GetPointClicked(P3.x, P3.y);

		if ((P1.y) < (UI.ToolBarHeight + 5) || (P2.y) < (UI.ToolBarHeight + 5) || (P3.y) < (UI.ToolBarHeight + 5) || (P1.y) > (UI.height - UI.StatusBarHeight + 5) || (P2.y) > (UI.height - UI.StatusBarHeight + 5) || (P3.y) > (UI.height - UI.StatusBarHeight + 5)) // window - status bar height to get y coordinate of statusbar
		{
			pOut->PrintMessage("In Valid points , Please Click points in drawing area , Click to draw triangle");
			pIn->GetPointClicked(x, y);	//Wait for any click


		}
		else invalid = false;

	} while (invalid);




	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, gfxInfo, false);

	// 2.3.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click=
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, gfxInfo, true);

	// 2.3.3 - Drawing a filled rectangle
	invalid = 1;

	do
	{
		pOut->PrintMessage("Drawing a triangle ==> filled, Click 3 points in drawing area");
		pIn->GetPointClicked(P1.x, P1.y);
		pIn->GetPointClicked(P2.x, P2.y);
		pIn->GetPointClicked(P3.x, P3.y);

		if ((P1.y) < (UI.ToolBarHeight + 5) || (P2.y) < (UI.ToolBarHeight + 5) || (P3.y) < (UI.ToolBarHeight + 5) || (P1.y) > (UI.height - UI.StatusBarHeight + 5) || (P2.y) > (UI.height - UI.StatusBarHeight + 5) || (P3.y) > (UI.height - UI.StatusBarHeight + 5)) // window - status bar height to get y coordinate of statusbar
		{
			pOut->PrintMessage("In Valid points , Please enter points in drawing area , Click to draw triangle");
			pIn->GetPointClicked(x, y);	//Wait for any click


		}
		else invalid = false;

	} while (invalid);


	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, gfxInfo, false);


	// 2.3.4 - Drawing highlighted filled tritangle
	pOut->PrintMessage("Drawing a triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, gfxInfo, true);





	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states
		// 2.3.1 - Drawing non-filled triangle
	invalid = 1;
	do
	{
		pOut->PrintMessage("Drawing a hexagon ==> non-filled,  Click centre");
		pIn->GetPointClicked(P1.x, P1.y);  // CENTRE OF HEXA
		if ((P1.y) - 61 < (UI.ToolBarHeight + 5) || (P1.y) + 61 > (UI.height - UI.StatusBarHeight + 5)  //  vertical validation : window hieght - tool bat height + 5 to be in safe
			|| ((P1.x) + 61) > (UI.width - 175) || (P1.x) - 61 < 0) // horizontal validation 
		{
			pOut->PrintMessage("Invalid centre , click to draw hexagon");
			pIn->GetPointClicked(x, y);	//Wait for any click

		}
		else invalid = 0;

	} while (invalid);

	int xc = P1.x, yc = P1.y;
	int x8coordinates[8] = { xc + 61,xc + 43,xc , xc - 43,xc - 63,xc - 43,xc,xc + 43 };
	int y8coordinates[8] = { yc ,yc - 43,yc - 61 ,yc - 43,yc,yc + 43,yc + 63,yc + 43 };


	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->Drawhexagon(x8coordinates, y8coordinates, gfxInfo, false);

	///	// 2.3.2 - Drawing highlighted non-filled hexangle

	pOut->PrintMessage("Drawing a hexagin ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawhexagon(x8coordinates, y8coordinates, gfxInfo, true);

	///////////////
		// 2.3.3 - Drawing a filled hexagon

	invalid = 1;
	do
	{
		pOut->PrintMessage("Drawing a hexagon ==> filled,  Click centre");
		pIn->GetPointClicked(P2.x, P2.y);  // CENTRE OF HEXA
		if ((P2.y) - 61 < (UI.ToolBarHeight + 5) || (P2.y) + 61 > (UI.height - UI.StatusBarHeight + 5)  //  vertical validation : window hieght - tool bat height + 5 to be in safe
			|| ((P2.x) + 61) > (UI.width - 175) || (P2.x) - 61 < 0) // horizontal validation 
		{
			pOut->PrintMessage("Invalid centre , click to draw hexagon");
			pIn->GetPointClicked(x, y);	//Wait for any click

		}
		else invalid = 0;

	} while (invalid);

	xc = P2.x, yc = P2.y;
	int x82coordinates[8] = { xc + 61, xc + 43,xc , xc - 43,xc - 63,xc - 43,xc,xc + 43 };
	int y82coordinates[8] = { yc     , yc - 43,yc - 61 ,yc - 43,yc,yc + 43,yc + 63,yc + 43 };
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->Drawhexagon(x82coordinates, y82coordinates, gfxInfo, false);

	/////////////highlighted -filled

	pOut->PrintMessage("Drawing a hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawhexagon(x82coordinates, y82coordinates, gfxInfo, true);




	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = GREEN;
	gfxInfo.isFilled = false;
	pOut->PrintMessage("Drawing a Circle ==> non-filled,  Click center and another point");
	pIn->GetPointClicked(P1.x, P1.y);
	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight) || (P1.x < 10) || (P1.x) >= UI.width - 20)
	{
		pOut->PrintMessage("wrong click another center");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click another point ");
	pIn->GetPointClicked(P2.x, P2.y);
	int r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	while (!((P1.y - r) > UI.ToolBarHeight + 5 && (P1.y + r) < UI.height - UI.StatusBarHeight) || (P1.x - r) < 5 || (P1.x + r) >= UI.width - 15)
	{
		pOut->PrintMessage("click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
		r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));

	}




	pOut->DrawCirc(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawCirc(P1, P2, gfxInfo, true);
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = YELLOW;
	gfxInfo.isFilled = true;
	pOut->PrintMessage("Drawing a Circle ==> filled,  Click center and another point");
	pIn->GetPointClicked(P1.x, P1.y);
	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("wrong click another center");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click another point ");
	pIn->GetPointClicked(P2.x, P2.y);
	r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	while (!((P1.y - r) > UI.ToolBarHeight + 5 && (P1.y + r) < UI.height - UI.StatusBarHeight) || (P1.x - r) < 5 || (P1.x + r) >= UI.width - 15)
	{
		pOut->PrintMessage("click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
		r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));

	}




	pOut->DrawCirc(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawCirc(P1, P2, gfxInfo, true);


	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");
	string s;
	s = "you entered : ";
	s += pIn->GetSrting(pOut);
	pOut->PrintMessage(s);
	Pause(1000);
	


	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar

	// 2- After reading the string clear the status bar

	// 3- print on the status bar "You Entered" then print the string

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();





	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;

		case DRAW_CIRC:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			break;

		case DRAW_SQUA:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			break;
		case DRAW_HEXA:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;
		case DRAW_TRIA:
			pOut->PrintMessage("Action: Draw a triangle , Click anywhere");
			break;
		case FUNC_LOAD:
			pOut->PrintMessage("Action: Load drawing , Click anywhere");
			break;
		case FUNC_PLAY_REC:
			pOut->PrintMessage("Action: Play recording , Click anywhere");
			break;
		case FUNC_SAVE:
			pOut->PrintMessage("Action: Save drawings , Click anywhere");
			break;
		case FUNC_REDO:
			pOut->PrintMessage("Action: Redo , Click anywhere");
			break;

		case FUNC_UNDO:
			pOut->PrintMessage("Action: Undo , Click anywhere");
			break;

		case FUNC_SELECT:
			pOut->PrintMessage("Action: select a drawing , Click anywhere");
			break;
		case FUNC_START_REC:
			pOut->PrintMessage("Action:Start recording, Click anywhere");
			break;
		case FUNC_STOP_REC:
			pOut->PrintMessage("Action:Stop recording , Click anywhere");
			break;
		case FUNC_ADD_IMAGE:
			pOut->PrintMessage("Action:Add image , Click anywhere");
			break;
		case COLOR_ORANGE:
			pOut->PrintMessage("Action:orange color, Click anywhere");
			break;
		case COLOR_BLACK:
			pOut->PrintMessage("Action:black color, Click anywhere");
			break;
		case COLOR_BLUE:
			pOut->PrintMessage("Action:blue color , Click anywhere");
			break;
		case COLOR_GREEN:
			pOut->PrintMessage("Action:green color, Click anywhere");
			break;
		case COLOR_RED:
			pOut->PrintMessage("Action:red color, Click anywhere");
			break;
		case COLOR_YELLOW:
			pOut->PrintMessage("Action:yellow color , Click anywhere");
			break;
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case CLEAR_CANVAS:
			pOut->PrintMessage("Action: a click on clear canvas, Click anywhere");
			break;
		case FUNC_FILL:
			pOut->PrintMessage("Action: a click on Fill color.");
			break;
		case FUNC_MOVE:
			pOut->PrintMessage("Action: a click on Move shape.");
			break;
		case FUNC_DELETE:
			pOut->PrintMessage("Action: a click on delete, Click on an item");
			break;

		case ENTER_PLAY_MODE:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			pOut->ClearStatusBar();
			break;

		case ENTER_DRAW_MODE:
			pOut->PrintMessage("Action: Switch to Draw Mode, Click anywhere");
			pOut->CreateDrawToolBar(); // Creates the Draw mode toolbar
			pOut->ClearStatusBar();
			break;

		case   BY_COLOR:
			pOut->PrintMessage("Action:Figure by Color , Click anywhere ");
			break;

		case  BY_SHAPE:
			pOut->PrintMessage("Action:Figure by Shape , Click anywhere");
			break;

		case  BY_COLOR_SHAPE:
			pOut->PrintMessage("Action:Figure by Shape & Color , Click anywhere");
			break;


		case FUNC_EXIT:
			pOut->PrintMessage("Action: Exitting");
			delete pIn;
			delete pOut;
			return 0;
			break;

		case FUNC_EXIT_playMode:
			pOut->PrintMessage("Action: Exitting");
			delete pIn;
			delete pOut;
			return 0;
			break;
		}
	} while (ActType != FUNC_EXIT && ActType != FUNC_EXIT_playMode);

	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}


