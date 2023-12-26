FROM ubuntu:latest

RUN apt update && apt install -y cmake git build-essential libssl-dev openssl wget clang-format gdb
RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.82.0/source/boost_1_82_0.tar.gz && tar -xvf boost_1_82_0.tar.gz && cd boost_1_82_0 && ./bootstrap.sh --prefix=/usr/ --with-libraries=system,json,thread && ./b2 install && cd / && rm -rf boost_1_82_0*
RUN git clone https://github.com/Thalhammer/jwt-cpp.git --branch v0.7.0 && cd jwt-cpp && mkdir build && cd build && cmake .. && make && make install && cd / && rm -rf jwt-cpp 
RUN wget https://github.com/plantuml/plantuml/releases/download/v1.2023.13/plantuml-1.2023.13.jar -O /root/plantuml.jar