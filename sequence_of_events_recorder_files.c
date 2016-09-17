#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
    Simulates a capture box in a car recording the last ten seconds of data about the braking system. Same as sequence_of_events_recorder.c,
    but with the addition of writing to an external file at the end as well. Instead of printing the data from the set we already have in memory,
    we read from the file after printing to print to the screen (I'm assuming just so we can practice reading from a file).
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
void print_data_file(Slice data_slices[], int partition, int length);
// Converts a slice of data to a row of data in the output table and prints it:
void print_slice_file(Slice data_slice, FILE * out_file);
// Prints data from input file to screen:
void print_from_file();
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

    // Print the data in the slices array to a file:
    print_data_file(data_slices, index, 100);

    // From the file we just wrote to, print to screen:
    print_from_file();

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

// Prints the data in a neat little table to an external file:
void print_data_file(Slice data_slices[], int partition, int length) {
    FILE * out_file = fopen("brakedata.txt", "w");
    if(out_file == NULL) {
        printf("Can't create the output file! Exiting.");
        exit(1);
    }
    fprintf(out_file, "%5s%15s%15s%15s%15s\n", "Time", "Brake fluid", "Disk brake", "Driver", "Power to");
    fprintf(out_file, "%5s%15s%15s%15s%15s\n", "(secs)", "pressure", "pressure", "pressure", "unit");
    int i;
    for(i = partition; i < length; i++) {
        print_slice_file(data_slices[i], out_file);
    }
    for(i = 0; i < partition; i++) {
        print_slice_file(data_slices[i], out_file);
    }
    fclose(out_file);
}

// Prints a slice of the data to the file (a row in the output table):
void print_slice_file(Slice data_slice, FILE * out_file) {
    if(out_file == NULL) {
        printf("Error! File does not exist.");
        exit(1);
    }
    fprintf(out_file, "%5.1f%15d%15d%15d%15d\n", data_slice.time, data_slice.brake_fluid_pressure, data_slice.disk_braking_pressure, data_slice.driver_brake_pressure, data_slice.brake_power);
}

// Prints from brakedata.txt file to screen:
void print_from_file() {
    FILE * input_file = fopen("brakedata.txt", "r");
    if(input_file == NULL) {
        printf("Error! Could not open file to read from. Exiting.");
        exit(1);
    }
    while(!feof(input_file)) {
        char in_str[65];
        fgets(in_str, 65, input_file);
        printf("%s", in_str);
    }
    fclose(input_file);
}
