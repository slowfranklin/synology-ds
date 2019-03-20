#ifndef MATH_TOOL_H
#define MATH_TOOL_H

#include <stdlib.h>

class MathTool {
public:
	// -5 % 3 = -2, use MathTool::GetPositiveMod(-5, 3) will get 1
	static int GetPositiveMod(int number, int modValue);
};

#endif /* MATH_TOOL_H */
