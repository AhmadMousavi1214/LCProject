# BCD Segment Library
## Introduction
In LC-Project we suppose to use *bcd-segment* to show entered password and numbers. so we create special library to handle this function.
It can use simple and by call the $DisplayPass()$ can show passwords easily.

## Importing
First download $BCDSegment.h$ and $BCDSegment.cpp$ then placed them in project folder.
In our project's include them and create object from class. 
Now can use functions by using the object and call functions', explained in next section
```cpp:
#include<BCDSegment.h>

int first_segment_pin = 1;

BCDSegment segment = BCDSegment(first_segment_pin);
```

## Explain Functions'
This library consists of two parts. $BCDSegment.h$ as *header file* and $BCDSegment.ccp$ as *body file* of code.
### Header
In header we have preview of $public$ and $private$ methods and properties.
#### Public's
In public's section we have $constructor$ and most important function, means, $DisplayPass()$. That is the only function from library can use, and this function *show password* on segments with the helps of other private method's.
#### Privates
Privates has $pins$ to save pins of segment's; $ClearAll()$ method-used in "DisplayPass()"- to clear all of the segments; $DisplayDigits()$ method to show only a digit on a segment.

### Body
In body we have definition of method's and properties, brought in header.
first we have const array for save *segment states*. for example pin's state of a bcd-segment to show `one` or `zero`.

#### constructor:
In constructor get first pin of a first segment and reserve after fifteen pins of arduino to use by all four bcd-segments.

#### ClearAll():
We call a segment is clear when all of it's pin's be off.
So clear all function makes all definition pin's off, that means *all pins set to LOW mode*.

#### DisplayDigit():
To show four digit, we have four segment, but set digit in all of them be same. so we have this function to show *entered digit* on *entered level segment*.
`lvl` is order of segments, first segment from left have `0` and last segment in right have `3` lvl.
we have four pin for every segments. so we move on every pins of segment and depend on *entered digit* we set them `low` or `high`. (we set state of them in cons array at the first of project)

#### DisplayPass():
get $pass$ from string and if length of that less than four, add `*` to end off it to show correctly in four segment.
Here we have to decide every char is *digit* or *null*?
If be digit, send it to $DisplayDigit()$ but else, show *null-char*, that's defined by `F` in displaying.
 In this function we have iterate `lvl` in `for()`.


## Using
After import library and create object from that.
every time we decision to show password, just call $DisplayPass()$ and pass password in *string* type.
bellow we have demo of using:
```cpp:
#include<BCDSegment.h>

int first_pin = 1;

BCDSegment segment = BCDSegment(firs_pin);

void setup(){
	string pass = "0000";

	// get string and it can be between 0 to 4 char.
	segment.DisplayPass(pass);
}
```