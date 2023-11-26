#include "stdint.h"
#include "project.h"

//Direcciones de registros por macros
#define Address_FISICO 0x68 //Direccion de I2C del periferico

#define ACCEL_XOUT_h 0x3B
#define CONFIG 0x1A
#define accel_config 0x1C
#define who_am_i 0x75

///BITFIELD DEL SENSOR SEGUN SU DATASHEET
typedef struct {
    
    //Sensado de los ejes del acelerometro
    int8_t ACCEL_XOUT_H;
    int8_t ACCEL_XOUT_L;
    int8_t ACCEL_YOUT_H;
    int8_t ACCEL_YOUT_L;
    int8_t ACCEL_ZOUT_H;
    int8_t ACCEL_ZOUT_L;
    
    //Temperatura
    int8_t TEMP_OUT_H;
    int8_t TEMP_OUT_L;
    
    //Sensados de los ejes del gyrocopio
    int8_t GYRO_XOUT_H;
    int8_t GYRO_XOUT_L;
    int8_t GYRO_YOUT_H;
    int8_t GYRO_YOUT_L;
    int8_t GYRO_ZOUT_H;
    int8_t GYRO_ZOUT_L;
    
    //Configuracion de acelometro
    uint8_t ACCEL_CONFIG;
    
    //Configuracion
    uint8_t PWR_MGMT_1;
    
    //Registro test
    uint8_t WHO_AM_I;
    
} MPU6050_registros;

///BITFIELD DEL SENSOR DATA DE LO SENSADO
typedef struct {
    
    //Sensado de los ejes del acelerometro
    int16_t ACCEL_XOUT;
    int16_t ACCEL_YOUT;
    int16_t ACCEL_ZOUT;
    
    //tEMPERATURA INTERNA DEL CHIP
    int16_t TEMP_OUT;
    
    //Sensado de los ejes del GYROSCOPIO
    int16_t GYRO_XOUT;
    int16_t GYRO_YOUT;
    int16_t GYRO_ZOUT;
    
} MPU6050_DATA;


// Definimos una estructura que agrupa el sensor y sus datos
struct MPU6050{
    MPU6050_registros registros;
    MPU6050_DATA DATA_SENSADO;
};

//Funciones para hacer comunicacion con el sensor
void MPU6050_Start(struct MPU6050 *registros);
void MPU6050_REGISTROS(struct MPU6050 *sensor); //Actualizamos las varibles de lectura de EJES 
void MPU6050_CONFIG_ACCEL(struct MPU6050 *registros, uint8_t AFS_SEL); //Actualizamos configuracion de ACELEROMETRO

//Demás funciones para configurado del sensor ...