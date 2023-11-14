typedef struct Sensor {
    int id;
    char name[12];
    int version;
    /*
     * The members of an anonymous union
     * are considered to be members of the
     * containing structure.
     */
    union { // Anonymous union
	float temperature;
	float humidity;
	char motion[4];
    };
} Sensor;
