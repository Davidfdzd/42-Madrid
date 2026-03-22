# User Documentation

## Overview

This project provides a containerized web infrastructure built with Docker.  
The stack includes the following services:

- **NGINX** — reverse proxy with TLS encryption
- **WordPress** — content management system used to serve the website
- **MariaDB** — database used by WordPress to store data

All services run inside Docker containers and communicate through a dedicated Docker network.

---

# Starting and Stopping the Project

## Start the infrastructure

To build and start all services, run:

```bash
make
```

This command will:

- Build the Docker images
- Create containers
- Create networks and volumes
- Start the services using Docker Compose

---

## Stop the infrastructure

To stop and remove the containers:

```bash
make down
```

This will stop the containers and remove them while preserving persistent data stored in volumes.

---

# Accessing the Website

Once the project is running, open a web browser and go to:

```
https://localhost
```

You should see the **WordPress installation page** if this is the first time running the project.

---

# Accessing the Administration Panel

After WordPress is installed, the administration panel can be accessed at:

```
https://localhost/wp-admin
```

From there, administrators can:

- Manage posts and pages
- Configure plugins
- Manage users
- Configure website settings

---

# Credentials

Credentials used by the services are defined in the environment configuration file.

Location:

```
srcs/.env
```

This file contains variables such as:

```
MYSQL_DATABASE
MYSQL_USER
MYSQL_PASSWORD
WP_ADMIN_USER
WP_ADMIN_PASSWORD
```

These credentials are used during the initialization of the containers.

---

# Checking That Services Are Running

You can verify that all services are running with:

```bash
docker ps
```

You should see containers for:

- nginx
- wordpress
- mariadb

---

## Viewing Logs

To inspect logs from the containers:

```bash
docker compose logs
```

This helps diagnose issues or confirm that services started correctly.

---

# Persistent Data

Project data is stored using Docker volumes.

This ensures that:

- WordPress files persist
- The MariaDB database persists
- Data is not lost when containers restart