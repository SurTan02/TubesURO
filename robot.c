/* Program ... */
/*  */

#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int x;
    int y;
} vektor;

/* Prototype Fungsi Robot */
/* Fungsi Gerak */
/*
point gerakRobot (point robotPosisi, char masukan[100]) {
    if (masukan == "maju") {
        robotPosisi.x =+ 1;
    } else if (masukan == "mundur") {
        robotPosisi.x =- 1;
    } else if (masukan == "kanan") {
        robotPosisi.y =+ 1;
    } else if (masukan == "kiri") {
        robotPosisi.y =- 1;
    }
    return robotPosisi;
}

vektor jarak (point a, point b) {
    vektor jarak;
    jarak.x = a.x - b.x;
    jarak.y = a.y - b.y;
    return jarak;
}

int menyerah() {
    return 0;
}

int jarakRobotKecoa (vektor robotJarak) {
    float skalar;
    skalar = sqrt(pow(robotJarak.x,2) + pow(robotJarak.y,2));
    return skalar;
}

int tembak (vektor robotJarak, int kecoaHealth) {
    if ((pow(robotJarak.x,2) + pow(robotJarak.y,2)) <= 9) {
        kecoaHealth =- 5;
    } else {
        printf("Tembakan meleset!");
    }
    return kecoaHealth;
}
*/
int visualisasi (point posisiRobot, point posisiKecoa) {
    int i, j;
    for (i = 20; i >= 0; --i) {
        for (j = 0; j <= 20; ++j) {
            if ((posisiRobot.y == i) && (posisiRobot.x == j)) {
                printf("R ");
            } else if ((posisiKecoa.y == i) && (posisiKecoa.x == j)) {
                printf("K ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*fungsi gerak kecoak*/
point mendekat(point robot, point kecoak){
	if (fabs(robot.x-kecoak.x) <= fabs(robot.y-kecoak.y)) {
		if ((kecoak.y-robot.y)<0) {
			kecoak.y =+ 1;
			
			return (kecoak);}
		else { 
			kecoak.y =-1;
			return (kecoak); 
			}
	}
	else {		// (fabs(robot.x - kecoak.x) > fabs(robot.y-kecoak.y))
		if ((kecoak.x - robot.x) <0) {
			kecoak.x =+1;
			return (kecoak);}
		else {
			kecoak.x =-1;
			return (kecoak); }
			}
		}
/*fungsi spawn*/
point spawn (point robot){

	point kecoak;
	srand(time(NULL));
	kecoak.x  = rand() % 20;
	kecoak.y = rand() % 20;
	
	while ((kecoak.x == robot.x) && (kecoak.y = robot.y)){
		kecoak.x  = rand() % 20;
		kecoak.y = rand() % 20;
	}
	return (kecoak);
}

/*fungsi serangan kecoak*/
int serang(point kecoak,point robot){
	double jarak2titik,x,y;
	x = kecoak.x - robot.x;
	y = kecoak.y - robot.y;
	jarak2titik = sqrt(x*x + y*y);
	if (jarak2titik < 2){
		return (-5);
}
	else{
		return(0);
	}
}
/*fungsi cek validitas dari input*/
int inputInvalid(char x){
	int benar;
	if (x ='maju' or x == 'mundur' or x=='kanan' or x=='kiri'or x=='menyerah'){
		return (1);
	}
	else {
		return (0);
	}
}



int main() {
    point posisiRobot, posisiKecoa;
    posisiRobot.x = 0;
    posisiRobot.y = 0;
    posisiKecoa.x = 20;
    posisiKecoa.y = 20;
    visualisasi (posisiRobot, posisiKecoa);
    return 0;
}
