FROM ubuntu:latest as build

RUN apt-get update && apt-get install -y cmake g++ make

WORKDIR /app

COPY CMakeLists.txt .
COPY /include ./include/
COPY /src ./src/

RUN mkdir build && cd build && cmake .. & make


FROM ubuntu:latest

WORKDIR /app

COPY --from=builder /app/build/ML-C++ .

CMD [ "./ML-C++" ]

