# Cocktail-Mixer

This cocktail-mixer is composed of several self-driving miniature car, where each one transports a cocktail glas from filling station to filling station where different beverages are added.

This project was initiated by the VDI Cologne Group 4-to-90 but it currently paused.

## Car

A self-driving Freenove-4WD-Car is controlled by an Arduino. It can navigate on a perpendicular grid of black lines (with unit lengths around 20cm) between filling stations which are placed on top of some line crossings. The car gets its instructions via radio frequency (using an RF24 radio chip) and sends its own location out.

Difficulties:
* The car has no external reference points, it knows its position and direction only due to counting crossings and turns. Therefore this counting has to be done precisely.
* Turning at a crossing involves several different car motions.

The car logic is already working, have a look at a [demonstration](https://nc.nullteilerfrei.de/index.php/s/nyYEFXyPgEe5ZH5)

## Control

The control - also an Arduino board with an RF24 radio chip - sends destination coordinates to the car via radio signal and receives the current position of the car. In the future, the control should coordinate the movement of several cars simultaneously.

The current rough implementation is sufficient to send destinations to one car.

## Filling Station

A filling station is positioned above one line crossing, includes currently four bottles for different beverages and one Arduino which controls pouring the beverages into the cocktail glas on top of the car. Each bottle has its own pump which pumps the liquid out of the bottle. The filling station itself knows which liquid is in which bottle and how long a pump has to pump to pour some ml of this specific beverage.

Alternatives:
* The control knows when a car is located underneath a specific filling station. It sends a singal to the filling station including the name and the amoung of the desired beverage.
* The car communicates with the filling station. Therefore the car has to know that it is located underneath a filling station and the desired amount of specific beverage.

The filling station implemention is not yet finished.

## Implementation

Mostly applies to the car:

* I tried to add as many domain knowledge as possible to the code to make the code easy and intuitive to read.
* Most non Arduino-specific code is covered by unit tests and a few integration tests.
* Design patterns are used where appropriate: The state pattern is used for the movements of the car (movement states are for example go straight, stopped or different turning states). With the observer pattern the car listens to the incoming radio signals and notifies the car of changes, such that it can adapt its driving direction. The car also listens to changes in its own position which changes when it arrives at a crossing and notifies its communication unit which sends this position via radio out.
