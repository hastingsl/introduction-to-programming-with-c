#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
    Simulates a capture box in a car recording the last ten seconds of data about the braking system.
*/

// A "slice" of data about the car:
typedef struct slice {
    int brake_fluid_pressure;
    int disk_braking_pressure;
    int driver_brake_pressure;
    int brake_power;
    float time;
} Slice;

// Start of function prototypes:
// Generates a random "slice" of data:
Slice generate_random_data();
// Generates a random number between max and min:
int generate_random_int(int min, int max);
// Prints the circular array of data slices:
void print_data(Slice data_slices[], int partition, int length);
// Converts a slice of data to a row of data in the output table and prints it:
void print_slice(Slice data_slice);
// End of function prototypes.

int main(void) {
    // Initialize random number generator:
    srand(time(NULL));

    float curr_time = 0;

    // Circular array:
    Slice data_slices[100];
    int cycle;
    int index = 0;
    // Runs the simulation:
    for(cycle = 0; cycle < 1077; cycle++) {
        if(index == 100) {
            index = 0;
        }
        data_slices[index] = generate_random_data();
        data_slices[index].time = curr_time;
        index++;
        curr_time += 0.1;
    }

    print_data(data_slices, index, 100);

    return 0;
}

// Generates a random "slice" of data:
Slice generate_random_data() {
    Slice sim_data;
    // Brake fluid pressure between 20 and 30 PSI:
    sim_data.brake_fluid_pressure = generate_random_int(20, 30);
    // Disk braking pressure between 10 to 15 PSI:
    sim_data.disk_braking_pressure = generate_random_int(10, 15);
    // Driver brake pressure between 30 and 40 PSI:
    sim_data.driver_brake_pressure = generate_random_int(30, 40);
    // Power to the braking unit between 10 and 100 watts:
    sim_data.brake_power = generate_random_int(10, 100);
    return sim_data;
}

// Generates a random number between min and max:
int generate_random_int(int min, int max) {
    return min + (rand() % (max - min));
}

// Prints the data in a neat little table to the console
void print_data(Slice data_slices[], int partition, int length) {
    printf("%5s%15s%15s%15s%15s\n", "Time", "Brake fluid", "Disk brake", "Driver", "Power to");
    printf("%5s%15s%15s%15s%15s\n", "(secs)", "pressure", "pressure", "pressure", "unit");
    int i;
    for(i = partition; i < length; i++) {
        print_slice(data_slices[i]);
    }
    for(i = 0; i < partition; i++) {
        print_slice(data_slices[i]);
    }
}

// Prints a slice of the data (a row in the output table):
void print_slice(Slice data_slice) {
    printf("%5.1f%15d%15d%15d%15d\n", data_slice.time, data_slice.brake_fluid_pressure, data_slice.disk_braking_pressure, data_slice.driver_brake_pressure, data_slice.brake_power);
}
