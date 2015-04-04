#ifndef __DivisionByZeroException_H__
#define __DivisionByZeroException_H__

#include <exception>

class DivisionByZeroException : std::exception{
public:
	virtual const char* what() const noexcept{
		return "Division by Zero";
	}
};

#endif /* __DivisionByZeroException_H__ */

