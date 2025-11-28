FROM ubuntu:16.04
RUN apt update && apt install -y g++
COPY main.cpp /app/main.cpp
WORKDIR /app
RUN g++ main.cpp -o main
CMD ["./main"]
