# Developer Documentation

## Overview

This document explains how developers can set up, build, and manage the project infrastructure.

The project uses **Docker** and **Docker Compose** to orchestrate multiple services in a containerized environment.

---

# Prerequisites

Before running the project, ensure the following tools are installed:

- Docker
- Docker Compose
- Make

You can verify the installations with:

```bash
docker --version
docker compose version
make --version
```

---

# Project Setup

## Clone the repository

```bash
git clone https://github.com/<login>/inception.git
cd inception
```

---

## Environment Configuration

Environment variables are stored in:

```
srcs/.env
```

This file contains configuration values used by the containers, such as:

- database credentials
- WordPress admin credentials
- domain name

Example variables:

```
MYSQL_DATABASE
MYSQL_USER
MYSQL_PASSWORD
WP_ADMIN_USER
WP_ADMIN_PASSWORD
DOMAIN_NAME
```

These variables are loaded automatically by Docker Compose.

---

# Building and Launching the Project

The infrastructure can be built and started using the Makefile.

```bash
make
```

This command will:

- Build all Docker images
- Create containers
- Configure networks
- Create persistent volumes
- Launch the full stack using Docker Compose

---

# Managing Containers

## List running containers

```bash
docker ps
```

---

## View container logs

```bash
docker compose logs
```

---

## Stop the infrastructure

```bash
make down
```

---

## Rebuild containers

If configuration or Dockerfiles change:

```bash
docker compose up --build
```

---

# Managing Docker Resources

## List Docker images

```bash
docker images
```

---

## List Docker volumes

```bash
docker volume ls
```

---

## List Docker networks

```bash
docker network ls
```

---

# Data Persistence

The project uses **Docker volumes** to store persistent data.

Persistent storage ensures that data remains available even if containers are stopped or removed.

Data stored includes:

- WordPress website files
- MariaDB database files

Volumes are automatically created by Docker Compose when the project is started.

Typical Docker volume location on the host system:

```
/var/lib/docker/volumes/
```

These volumes ensure that:

- database data is not lost
- website content persists between container restarts

---

# Project Structure

```
.
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── Makefile
└── srcs
    ├── docker-compose.yml
    ├── .env
    └── requirements
        ├── mariadb
        ├── nginx
        └── wordpress
```

Each service contains its own **Dockerfile** and configuration files.

---

# Notes for Developers

- Each service runs in an isolated container.
- Services communicate through a Docker network.
- Persistent data is stored in Docker volumes.
- The infrastructure is defined in **docker-compose.yml**.