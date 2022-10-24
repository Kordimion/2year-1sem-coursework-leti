#pragma once

enum class ErrorActionTypes
{
	ErrorResolved = 10,
	NotImplementedError,
	IncorrectInputError
};

enum class UnitActionTypes
{
	SelectUnitType = 20,
	AddUnit,
	DeleteUnit
};