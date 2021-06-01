/* device.h */

#ifndef GDMPR_DEVICE_H
#define GDMPR_DEVICE_H

#include "core/reference.h"
#include "core/func_ref.h"
#include "core/variant.h"
#include <mapper_cpp.h>


class gdMprDevice : public Reference {
    GDCLASS(gdMprDevice, Reference);

    protected:
        // Required for binding methods to godot 
        static void _bind_methods();


    public:

        


        mapper::Device* dev;
        std::vector<mapper::Signal> signals;

        // Method headers go here

        void init(String name);
        int poll_blocking(int block_ms);
        int poll();
        bool ready();

        // Optional fields have been omitted for now
        void add_sig(String direction, String name, int length, String datatype);
        mapper::Signal sig_get(String name);

        // Godot method binding fails when using templates, method overridding, or copying into Variant type.
        void set_value_int(String signalName, int32_t value);
        void set_value_float(String signalName, float value);
        void set_value_double(String signalName, double value);

        const Variant& value (String signalName);
        int32_t value_int(String signalName);
        float value_float(String signalName);
        double value_double(String signalName);
            

        gdMprDevice();
        ~gdMprDevice();


};

#endif // GDMPR_DEVICE_H