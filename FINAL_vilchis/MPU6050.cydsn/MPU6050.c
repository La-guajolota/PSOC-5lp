#include "MPU6050.h"

//Funciones de protocolo I2C
static int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){

    int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */
    uint16_t i = 0;

    /*
     * The parameter dev_id can be used as a variable to store the I2C address of the device
     */

    /*
     * Data on the bus should be like
     * |------------+---------------------|
     * | I2C action | Data                |
     * |------------+---------------------|
     * | Start      | -                   |
     * | Write      | (reg_addr)          |
     * | Stop       | -                   |
     * | Start      | -                   |
     * | Read       | (reg_data[0])       |
     * | Read       | (....)              |
     * | Read       | (reg_data[len - 1]) |
     * | Stop       | -                   |
     * |------------+---------------------|
     */

    //psoc5
    rslt = I2C_MasterSendStart(dev_id,I2C_WRITE_XFER_MODE);//mANDA COMANDO
    rslt = I2C_MasterWriteByte(reg_addr);//Envia registro
    rslt = I2C_MasterSendRestart(dev_id,I2C_READ_XFER_MODE);//Paro para Leer datos
    
    while(i < (len - 1)) {
      
        reg_data[i] = I2C_MasterReadByte(I2C_ACK_DATA);//ack
        i++;
     
    }
    
    reg_data[i] = I2C_MasterReadByte(I2C_NAK_DATA);//nak
    rslt = I2C_MasterSendStop();
    
    return rslt;
}

static int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){
    int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */
    uint16_t i = 0;

    /*
     * The parameter dev_id can be used as a variable to store the I2C address of the device
     */

    /*
     * Data on the bus should be like
     * |------------+---------------------|
     * | I2C action | Data                |
     * |------------+---------------------|
     * | Start      | -                   |
     * | Write      | (reg_addr)          |
     * | Write      | (reg_data[0])       |
     * | Write      | (....)              |
     * | Write      | (reg_data[len - 1]) |
     * | Stop       | -                   |
     * |------------+---------------------|
     */
    
    rslt = I2C_MasterSendStart(dev_id, I2C_WRITE_XFER_MODE);//rw =0  Escribimos comando
    rslt = I2C_MasterWriteByte(reg_addr);//Mandamos dirección de registo para escribir en el
    
    while(i < len) {
        
        rslt = I2C_MasterWriteByte(*reg_data);
        i++;
        reg_data++;
        
    }
    
    rslt = I2C_MasterSendStop();
    
    return rslt;
}

void MPU6050_Start(struct MPU6050 *registros){
    
    uint8_t data[2] = {0,0};
    user_i2c_write(Address_FISICO,0x6B,data,1);//power manageent
    
    //Lectura de registros configurados
    user_i2c_read(Address_FISICO,0x6B,data+1,0);
    registros->registros.PWR_MGMT_1 = data[1];
    
}

void MPU6050_CONFIG_ACCEL(struct MPU6050 *registros, uint8_t AFS_SEL){
    
    uint8_t data[2] = {AFS_SEL<<3,0};

    //Escritura de configuraciones
    user_i2c_write(Address_FISICO,accel_config,data,1);//Acualizamos el registro del sensor
    
    //Lectura de registros configurados
    user_i2c_read(Address_FISICO,accel_config,data+1,0);//Se lee los registros cambiados
    registros->registros.ACCEL_CONFIG = data[1];
    
}

void MPU6050_REGISTROS(struct MPU6050 *sensor){
    
    uint8_t reg_data[15];
    
    user_i2c_read(Address_FISICO,ACCEL_XOUT_h,reg_data,13);//Se lee los registros de lo sensado del acelerometro
    user_i2c_read(Address_FISICO,who_am_i,reg_data+14,0);
    
    //Acelerometro
    sensor->registros.ACCEL_XOUT_H = reg_data[0];
    sensor->registros.ACCEL_XOUT_L = reg_data[1];
    sensor->registros.ACCEL_YOUT_H = reg_data[2];
    sensor->registros.ACCEL_YOUT_L = reg_data[3];
    sensor->registros.ACCEL_ZOUT_H = reg_data[4];
    sensor->registros.ACCEL_ZOUT_L = reg_data[5];
    
    sensor->DATA_SENSADO.ACCEL_XOUT = ((sensor->registros.ACCEL_XOUT_H << 8) | (sensor->registros.ACCEL_XOUT_L));
    sensor->DATA_SENSADO.ACCEL_YOUT = ((sensor->registros.ACCEL_YOUT_H << 8) | (sensor->registros.ACCEL_YOUT_L));
    sensor->DATA_SENSADO.ACCEL_ZOUT = ((sensor->registros.ACCEL_ZOUT_H << 8) | (sensor->registros.ACCEL_ZOUT_L));
    
    //Temperatura
    sensor->registros.TEMP_OUT_H = reg_data[6];
    sensor->registros.TEMP_OUT_L = reg_data[7];
    
    sensor->DATA_SENSADO.TEMP_OUT = ((sensor->registros.TEMP_OUT_H << 8) | (sensor->registros.TEMP_OUT_L))/340 +36.53;
    
    //Gyroscopio
    sensor->registros.GYRO_XOUT_H = reg_data[8];
    sensor->registros.GYRO_XOUT_L = reg_data[9];
    sensor->registros.GYRO_YOUT_H = reg_data[10];
    sensor->registros.GYRO_YOUT_L = reg_data[11];
    sensor->registros.GYRO_ZOUT_H = reg_data[12];
    sensor->registros.GYRO_ZOUT_L = reg_data[13];
    
    sensor->DATA_SENSADO.GYRO_XOUT = ((sensor->registros.GYRO_XOUT_H << 8) | (sensor->registros.GYRO_XOUT_L));
    sensor->DATA_SENSADO.GYRO_YOUT = ((sensor->registros.GYRO_YOUT_H << 8) | (sensor->registros.GYRO_YOUT_L));
    sensor->DATA_SENSADO.GYRO_ZOUT = ((sensor->registros.GYRO_ZOUT_H << 8) | (sensor->registros.GYRO_ZOUT_L));
    
    //Who_am_i 
    
    sensor->registros.WHO_AM_I = reg_data[14];
    
} 