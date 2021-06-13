#include "Ladder.h"

Ladder::Ladder()
{

}

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	StartCell = startCellPos;

}

CellPosition Ladder::GetEndPositionOfCell(Ladder * l) {
	return l->endCellPos;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);

}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("You have reached a ladder. Click to continue ...");

	
		pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

void Ladder::Save(ofstream & OutFile, TYPE LADDER)
{
	OutFile << GameObject::position.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;
}

void Ladder::Read(ifstream & Infile)
{

	int start, end;
	CellPosition s, e;
	Infile >> start >> end;
	GameObject::position = s.GetCellPositionFromNum(start);
	endCellPos = e.GetCellPositionFromNum(end);


}



CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

CellPosition Ladder::GetStartPosition() const
{
	return StartCell;
}

Ladder::~Ladder()
{

}
