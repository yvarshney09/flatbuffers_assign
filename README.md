# flatbuffers_assign
The flatbuffers schema can be compiled using flatc compiler present in the flatbuffers folder.
sender.cpp is the source file in cpp to generae the serialized message. It can be compiled with command g++ -I/<include path for flatbuffers> -o fb_encoder sedner.cpp
The decode is written in python named fb_decoder.py. To run the decoder, need to pass the generated binary file from encoder as second command line argument. eg. python fb_decoder.py <bin file path with messages>
