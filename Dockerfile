# Multi-stage build for minimal static binary
# Stage 1: Build stage with Alpine
FROM alpine:3.18 AS builder

# Install build dependencies
RUN apk add --no-cache \
    build-base \
    cmake \
    make \
    gcc \
    g++ \
    musl-dev \
    linux-headers

WORKDIR /app

COPY CMakeLists.txt ./
COPY include/ ./include/
COPY src/ ./src/
COPY tests/ ./tests/

# Build with static linking
RUN mkdir -p build && \
    cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-static" .. && \
    make -j$(nproc) && \
    strip calculator_app calculator_test_harness

# Stage 2: Minimal runtime stage
FROM scratch

# Copy only the static executables
COPY --from=builder /app/build/calculator_app /calculator_app

# Default command
ENTRYPOINT ["/calculator_app"]