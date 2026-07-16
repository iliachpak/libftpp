FROM debian:trixie

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y \
    build-essential \
    cmake \
    ninja-build \
    gdb \
    git \
    clang \
    clang-format \
    valgrind \
    pkg-config \
    lcov \
    gcovr \
    vim \
    sudo \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -ms /bin/bash developer \
    && echo "developer ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER developer

WORKDIR /workspace

CMD ["/bin/bash"]
