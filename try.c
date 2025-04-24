#ifndef CONV_H
#define CONV_H

#include <systemc.h>

SC_MODULE(Convolution) {
    // Ports
    sc_in<bool> clk;
    sc_in<bool> rst;
    sc_in<sc_int<16>> data_in;    // Input data
    sc_out<sc_int<32>> data_out;  // Output data
    
    // Internal signals
    static const int KERNEL_SIZE = 3;
    sc_int<16> kernel[KERNEL_SIZE] = {1, 2, 1};  // Example kernel
    sc_int<16> buffer[KERNEL_SIZE];
    
    void conv_process() {
        if (rst) {
            // Reset buffer
            for (int i = 0; i < KERNEL_SIZE; i++) {
                buffer[i] = 0;
            }
            data_out.write(0);
        } else {
            // Shift buffer
            for (int i = KERNEL_SIZE-1; i > 0; i--) {
                buffer[i] = buffer[i-1];
            }
            buffer[0] = data_in.read();
            
            // Compute convolution
            sc_int<32> sum = 0;
            for (int i = 0; i < KERNEL_SIZE; i++) {
                sum += buffer[i] * kernel[i];
            }
            data_out.write(sum);
        }
    }
    
    SC_CTOR(Convolution) {
        SC_METHOD(conv_process);
        sensitive << clk.pos();
    }
};

#endif