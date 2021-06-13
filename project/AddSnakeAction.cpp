#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"



AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp) // contructor
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	//validate
	flag = pGrid->ValidateSnake(startPos, endPos);


	if (!flag)
		pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	ReadActionParameters();
	if (flag) //if passed validations
	{
		// Create a snake object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
				
		// Add the card object to the GameObject of its Cell
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}
}

AddSnakeAction::~AddSnakeAction()
{
}
