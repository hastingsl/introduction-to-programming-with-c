#include <stdio.h>
#include <stdlib.h>

/**
  Program for practicing C console input/output and use of define directives. The program:
  1. Calculates and outputs the diameter and radius of the Earth at the equator from the circumference.
  2. Converts and outputs the distance in miles between Orlando and Paris to kilometers.
  3. Calculates and outputs how long it would take a jetliner to fly from Orlando to Paris assuming a ground speed of 565 mph.
  4. Calculates and outputs how much earlier it would take an aircraft going at the same speed to reach Rome at the same time the first
      jetliner reaches Paris.
*/

// Start of define directives
#define PI 3.14
#define CIRCUMFERENCE 24874
#define DISTANCE_ORLANDO_PARIS 4487
#define AIR_SPEED 565
#define DISTANCE_ORLANDO_ROME 5113
// Kilometers in a mile:
#define KM_TO_MI 1.60934
// End of define directives

int main(void) {

  float diameter = CIRCUMFERENCE / PI;
  float radius = diameter / 2;
  printf("The diameter of the Earth at the equator is %.2f miles.\n", diameter);
  printf("The radius of the Earth at the equator is %.2f miles.\n", radius);

  // Calculate distance between Orlando and Paris in kilometers:
  float distance_orlando_paris = DISTANCE_ORLANDO_PARIS * KM_TO_MI;
  printf("The distance between Orlando and Paris in kilometers is %.2f.\n", distance_orlando_paris);

  // Calculate time to Paris from Orlando:
  float time_orlando_paris = DISTANCE_ORLANDO_PARIS / AIR_SPEED;
  printf("It takes %.2f hours to fly from Orlando to Paris going at 565 miles per hour.\n", time_orlando_paris);

  // Calculates how much earlier a plane going to Rome would need to leave Orlando:
  float time_orlando_rome = DISTANCE_ORLANDO_ROME / AIR_SPEED;
  float diff = time_orlando_rome - time_orlando_paris;
  printf("To reach Rome at the same time the plane would reach Paris going at the same speed, you would need to depart %.2f hours earlier.\n", diff);

  return 0;
}
