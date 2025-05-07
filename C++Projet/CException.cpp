#include "CException.h"

CException::CException() {
	uiEXCVal = FAUX;
}

CException::CException(unsigned int uiVal) {
	uiEXCVal = uiVal;
}

CException::CException(const CException& Exc) {
	uiEXCVal = Exc.EXCGet_Val();
}

unsigned int CException::EXCGet_Val() const {
	return uiEXCVal;
}

void CException::EXCModifier_Val(unsigned int uiVal) {
	uiEXCVal = uiVal;
}