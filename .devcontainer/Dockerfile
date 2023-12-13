FROM ubuntu:latest

RUN apt update && apt install -y cmake git build-essential libssl-dev openssl wget
RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.82.0/source/boost_1_82_0.tar.gz && tar -xvf boost_1_82_0.tar.gz && cd boost_1_82_0 && ./bootstrap.sh --prefix=/usr/ --with-libraries=system,json,thread && ./b2 install