

#include <iostream>

// an enum creates a set of ints that map to a symbolic identifier
// the class forces static typing for that enumeration
//	that is, you can't use another enum's numeric value in its place
enum class Color {
	red,
	blue,
	green
};

enum class Traffic_Light {
	green,
	yellow,
	red
};

// note that all these values are in their enum's scope
Color col = Color::red;
Traffic_Light light = Traffic_Light::red;

// because of static typing, this wouldn't work
// Traffic_Light another_light = Color::red;
// and you couldn't substitute an int value
// Traffic_Light another_light = 1

// enums have assignment, init, and comparisons (=, ==, <, >) predefined
// but operators can be overwritten and expanded
Traffic_Light& operator++(Traffic_Light& t) {
	switch (t) {
	case Traffic_Light::green: return t = Traffic_Light::yellow;
	case Traffic_Light::yellow: return t = Traffic_Light::red;
	case Traffic_Light::red: return t = Traffic_Light::green;
	}
}