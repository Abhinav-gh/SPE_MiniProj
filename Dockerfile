# Multi-stage build 
# Stage 1: Build stage
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY CMakeLists.txt ./
COPY include/ ./include/
COPY src/ ./src/
COPY tests/ ./tests/

RUN mkdir -p build && \
    cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release .. && \
    make -j$(nproc)

# Stage 2: Runtime stage
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    rm -rf /var/lib/apt/lists/* && \
    apt-get clean

WORKDIR /app

COPY --from=builder /app/build/calculator_app ./
COPY --from=builder /app/build/calculator_test_harness ./

CMD ["./calculator_test_harness"]