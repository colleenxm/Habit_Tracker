# Project Proposal

## Brief Overview
I plan to build a habit tracker for users to create goals and check in regularly over a period of time, ending with a visual representation
of their commitment to their habits, like the hand written example below.

![Example](https://i.pinimg.com/originals/ca/c1/56/cac1563b454d07db266240fc45854ed1.jpg)

## Anticipated Steps
1) Build interface class for users to add goals
2) Create access utils to create file/store user data and make app access/pretty print user data given user name
3) Build visual graph and buttons for user to check off their completion of a habit on a given day.
4) Integrate quote API to having opening screen of app display motivation quote
5) Add customization of length of time for tracking (ie basic app would track/display a week at a time, but ideally users can track a whole
month if they wanted to.)
6) Access date for tracking purposes using world clock API so that app functions like a calendar, integrating with the adjustable time
length feature
7) Allow for to select which color they want using color theory addon

## Libraries and APIs Used
* ofxJSON - Wrapper for jsoncpp for openFrameworks
* ofxColorTheory for color palette
* https://theysaidso.com/api/#qod - API to get a new quote of the day
* http://worldclockapi.com/ - API to get current time and date

Code will be based off of example code from openFrameworks gui example code found here: 
https://github.com/openframeworks/openFrameworks/tree/master/examples/gui/guiExample


