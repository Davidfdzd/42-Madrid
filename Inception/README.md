*This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>]].*

# Inception

## Description

Inception is a system administration project from the 42 curriculum focused on infrastructure using **Docker**.  
The goal is to build a small containerized infrastructure composed of multiple services using **Docker Compose**, following strict constraints regarding containerization, networking, and security.

The project requires setting up and orchestrating several services such as:

- **NGINX** (with TLS)
- **WordPress**
- **MariaDB**
- Persistent **Docker volumes**
- Secure environment configuration
- Custom **Docker images** built from scratch (no pre-built images)

Each service runs inside its own container and communicates through a dedicated Docker network.

The infrastructure must follow best practices such as:
- container isolation
- persistent data storage
- secure secrets management
- reproducible builds

This project introduces the fundamentals of **DevOps**, **containerization**, and **infrastructure automation**.

---

# Project Architecture

The infrastructure is built using **Docker Compose**, which orchestrates multiple containers:

```
        Internet
            │
        NGINX (TLS)
            │
      Docker Network
      ┌───────────────┐
      │               │
   WordPress       MariaDB
      │
  Docker Volume
```


### Services

| Service | Description |
|------|------|
| **NGINX** | Reverse proxy with TLS encryption |
| **WordPress** | PHP CMS serving the website |
| **MariaDB** | Database storing WordPress data |

---

# Docker in This Project

Docker is used to create **isolated environments** for each service.

Each container:
- runs a **single service**
- is built from a **custom Dockerfile**
- communicates through a **Docker network**
- stores persistent data in **Docker volumes**

Advantages:

- reproducibility
- environment isolation
- easy deployment
- scalable infrastructure

---

# Design Choices

### Why Docker Compose

Docker Compose allows us to:

- define infrastructure in code
- easily start all services
- manage networks and volumes automatically

---

# Virtual Machines vs Docker

| Virtual Machines | Docker |
|---|---|
| Full OS virtualization | Application-level virtualization |
| Heavy (GBs) | Lightweight (MBs) |
| Slower startup | Instant startup |
| More resource usage | Efficient resource usage |

Docker containers share the host kernel, which makes them much faster and lighter than virtual machines.

---

# Secrets vs Environment Variables

### Environment Variables

Environment variables are commonly used to pass configuration to containers:

Examples:
- MYSQL_USER
- MYSQL_PASSWORD
- DOMAIN_NAME

However, they are **not secure for sensitive data** because they can be exposed in logs or container inspection.

### Docker Secrets

Docker secrets are designed for **secure storage of sensitive information**, such as:

- database passwords
- API keys
- certificates

Secrets are mounted into containers as **temporary files**, improving security.

---

# Docker Network vs Host Network

### Docker Network

Docker networks allow containers to communicate using **internal DNS**.

Example:
- wordpress -> mariadb

Advantages:

- container isolation
- internal service discovery
- improved security

### Host Network

Host networking removes network isolation and allows containers to share the host network stack.

Drawbacks:

- less secure
- port conflicts
- reduced isolation

For this project, **Docker networks are preferred**.

---

# Docker Volumes vs Bind Mounts

### Docker Volumes

Volumes are managed by Docker and stored in: /var/lib/docker/volumes/


Advantages:

- portable
- safe from accidental modification
- easier backups

Used for:

- WordPress files
- MariaDB database

### Bind Mounts

Bind mounts map a host directory directly into a container.

Example:
- /home/user/data:/var/lib/mysql


Advantages:

- easier debugging
- direct host access

Drawbacks:

- less portable
- depends on host filesystem

For this project, **Docker volumes ensure better portability and persistence**.

---

# Instructions

## Requirements

- Linux environment (recommended)
- Docker
- Docker Compose
- Make

### Install Docker

Official documentation:

https://docs.docker.com/engine/install/

---

# Installation

Clone the repository:

```bash
git clone https://github.com/<login>/inception.git
cd inception
```

Build and start the infrastructure:

```bash
make
```

This command will:

- Build the Docker images defined in the project
- Create the containers required for each service
- Set up the Docker network
- Create persistent Docker volumes
- Start the full infrastructure using Docker Compose

---

# Usage

Once the containers are running, open your browser and go to:

```
https://localhost
```

You should see the **WordPress installation page**, where you can finish configuring your website.

The request flow works as follows:

1. The user connects to **NGINX** through HTTPS.
2. **NGINX** forwards requests to the **WordPress** container.
3. **WordPress** communicates with **MariaDB** to store and retrieve data.

---

# Project Structure

```
.
├── Makefile
├── README.md
└── srcs
    ├── docker-compose.yml
    ├── .env
    └── requirements
        ├── mariadb
        │   ├── Dockerfile
        │   └── conf
        ├── nginx
        │   ├── Dockerfile
        │   └── conf
        └── wordpress
            ├── Dockerfile
            └── conf
```

### Structure Overview

- **Makefile**  
  Provides simple commands to build, start, and manage the project.

- **docker-compose.yml**  
  Defines the services, volumes, and networks used in the infrastructure.

- **.env**  
  Contains environment variables used by the containers.

- **requirements/**  
  Contains the Dockerfiles and configuration files for each service.

---

# Resources

### Official Documentation

- Docker Documentation  
https://docs.docker.com/

- Docker Compose Documentation  
https://docs.docker.com/compose/

- NGINX Documentation  
https://nginx.org/en/docs/

- MariaDB Documentation  
https://mariadb.org/documentation/

- WordPress Documentation  
https://developer.wordpress.org/

---

# AI Usage

Artificial Intelligence tools were used during this project to assist with:

- Understanding Docker and container orchestration concepts
- Troubleshooting configuration and networking issues
- Reviewing Dockerfile and Docker Compose configurations
- Improving the structure and clarity of the project documentation

AI was used strictly as a **learning and support tool**, while the implementation, configuration, and debugging of the infrastructure were completed manually by the project authors.

---

# Authors

- <login1>
- <login2>
- <login3>