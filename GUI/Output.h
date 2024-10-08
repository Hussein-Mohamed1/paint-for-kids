#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	string TEXT; // STRING TSET
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;
	///Make similar functions for drawing all other figure types.//Draw a rectangle
	void Output::Drawrtriangle(int x1, int y1, int x2, int y2, int x3, int y3, GfxInfo RectGfxInfo, bool selected) const;
	void Output::DrawCirc(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;
	void Drawhexagon(const int* xcoordinates, const int* ycoordinates, GfxInfo RectGfxInfo, bool selected) const;
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif