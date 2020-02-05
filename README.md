# GameAI
 
To run: Move project into openframeworks/apps/myApps/ then open in Visual Studio 2017.

To change run mode, in main.cpp uncomment a different ofRunApp()

Files:

BasicAI is where all the algorithms are located.
Boid is my basic object.
RBody holds my RigidBody, Steering, and Vector2 structs.
Basic-Motion is the app for kinematic motion.
SteerWander is the app for steering and wandering. (to switch between the two you uncomment the steer or wander line and comment the other.)
ofApp is the app for flocking.
SteerObj is the object used for arrive behavior.
WanderObj is the object used for wander behavior.
FlockingObj is the object used for flocking behavior.
