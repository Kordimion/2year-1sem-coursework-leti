#pragma once

enum class ErrorActionTypes {
	ErrorResolved = 10,
	NotImplementedError,
	IncorrectInputError
};

enum class UnitActionTypes {
	SelectUnitCreationType = 20,
	AddUnit,
	SelectUnitStarted,
	SelectUnitStopped,
	SelectNextUnit,
	SelectPreviousUnit,
	DeleteSelectedUnit,
	MoveUnitStarted,
	MoveUnit,
	MoveUnitCanceled
};
