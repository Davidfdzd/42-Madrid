#!/bin/sh
set -e

echo "[$(date '+%Y-%m-%d %H:%M:%S')] 🚀 Initializing MariaDB setup...🚀"

### COMPROBACIÓN DE VARIABLES ###
: "${MYSQL_DATABASE:?Variable MYSQL_DATABASE is not set}"
: "${MYSQL_USER:?Variable MYSQL_USER is not set}"
: "${MYSQL_PASSWORD:?Variable MYSQL_PASSWORD is not set}"
: "${MYSQL_ROOT_PASSWORD:?Variable MYSQL_ROOT_PASSWORD is not set}"
: "${MYSQL_ADMIN_USER:?Variable MYSQL_ADMIN_USER is not set}"
: "${MYSQL_ADMIN_PASSWORD:?Variable MYSQL_ADMIN_PASSWORD is not set}"

## PERMISOS A MARIADB ##
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

# --- AQUÍ VA TU BLOQUE ---
if [ ! -d "/var/lib/mysql/mysql" ]; then
  echo "[$(date '+%Y-%m-%d %H:%M:%S')] 📦 MariaDB directory not found. Initializing...📦"
  
  # 1. Inicializa las tablas del sistema
  mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

  # 2. Ejecuta los comandos SQL mediante el modo bootstrap
  mysqld --user=mysql --bootstrap << EOF
FLUSH PRIVILEGES;

-- Configuración de Base de Datos
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8 COLLATE utf8_general_ci;

-- Usuario de aplicación
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

-- Usuario admin
CREATE USER IF NOT EXISTS '${MYSQL_ADMIN_USER}'@'%' IDENTIFIED BY '${MYSQL_ADMIN_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_ADMIN_USER}'@'%' WITH GRANT OPTION;

-- Seguridad Root
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

FLUSH PRIVILEGES;
EOF

  echo "[$(date '+%Y-%m-%d %H:%M:%S')] ✅ MariaDB database initialized ✅"
else
  echo "[$(date '+%Y-%m-%d %H:%M:%S')] ✔️ MariaDB database already present ✔️"
fi
# --- FIN DEL BLOQUE ---

exec mariadbd --user=mysql --console --port=3306 --bind-address=0.0.0.0