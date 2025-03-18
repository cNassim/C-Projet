#include "CException.h"

CException::CException() {
	uiEXCVal = FAUX; // L'exception est initialis�e
}
CException::CException(unsigned int uiVal) {
	uiEXCVal = uiVal;
}
CException::CException(CException& Exc) {
	uiEXCVal = Exc.EXCGet_Val();
}
unsigned int CException::EXCGet_Val() {
	return uiEXCVal;
}
void CException::EXCModifier_Val(unsigned int uiVal) {
	uiEXCVal = uiVal;
}