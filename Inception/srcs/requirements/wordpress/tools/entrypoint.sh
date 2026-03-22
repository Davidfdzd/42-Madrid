#!/bin/bash
set -e

export WP_CLI_SUPPRESS_PHP_WARNINGS=1

echo "[$(date '+%Y-%m-%d %H:%M:%S')] 🚀 Starting WordPress setup..."

WORDPRESS_PATH="/var/www/wordpress"

: "${WORDPRESS_DB_HOST:?❌ WORDPRESS_DB_HOST is not set}"
: "${WORDPRESS_DB_USER:?❌ WORDPRESS_DB_USER is not set}"
: "${WORDPRESS_DB_PASSWORD:?❌ WORDPRESS_DB_PASSWORD is not set}"
: "${WORDPRESS_DB_NAME:?❌ WORDPRESS_DB_NAME is not set}"
: "${DOMAIN_NAME:?❌ DOMAIN_NAME is not set}"
: "${WP_ADMIN:?❌ WP_ADMIN is not set}"
: "${WP_ADMIN_PASSWORD:?❌ WP_ADMIN_PASSWORD is not set}"
: "${WP_ADMIN_EMAIL:?❌ WP_ADMIN_EMAIL is not set}"
: "${WP_USER:?❌ WP_USER is not set}"
: "${WP_PASSWORD:?❌ WP_PASSWORD is not set}"

# Esperar MariaDB
until mysqladmin ping -h"$WORDPRESS_DB_HOST" -u"$WORDPRESS_DB_USER" -p"$WORDPRESS_DB_PASSWORD" --silent; do
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] ⏳ Waiting for MariaDB at $WORDPRESS_DB_HOST..."
    sleep 2
done

WP_URL="https://${DOMAIN_NAME}"
export HTTP_HOST=$DOMAIN_NAME

# 1️⃣ Descargar WordPress si no existe
if [ ! -f "$WORDPRESS_PATH/wp-load.php" ]; then
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] 📥 Downloading WordPress core..."
    wp core download --path="$WORDPRESS_PATH" --allow-root
fi

# 2️⃣ Crear wp-config.php si no existe
if [ ! -f "$WORDPRESS_PATH/wp-config.php" ]; then
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] 📝 Creating wp-config.php..."
    wp config create \
        --dbname="$WORDPRESS_DB_NAME" \
        --dbuser="$WORDPRESS_DB_USER" \
        --dbpass="$WORDPRESS_DB_PASSWORD" \
        --dbhost="$WORDPRESS_DB_HOST" \
        --path="$WORDPRESS_PATH" \
        --allow-root --force

    wp config set WP_HOME "$WP_URL" --path="$WORDPRESS_PATH" --allow-root --type=constant
    wp config set WP_SITEURL "$WP_URL" --path="$WORDPRESS_PATH" --allow-root --type=constant
fi

# 3️⃣ Instalar WordPress si no está instalado
if ! wp core is-installed --path="$WORDPRESS_PATH" --allow-root; then
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] 🔧 Installing WordPress..."
    wp core install \
        --url="$WP_URL" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --path="$WORDPRESS_PATH" \
        --allow-root

    echo "[$(date '+%Y-%m-%d %H:%M:%S')] 👑 Admin '$WP_ADMIN' created!"
else
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] ✔️ WordPress already installed."
fi

# 4️⃣ Crear usuario secundario SOLO si no existe
WP_USER_EMAIL="${WP_USER_EMAIL:-${WP_USER}@${DOMAIN_NAME}}"

if ! wp user get "$WP_USER" --path="$WORDPRESS_PATH" --allow-root &>/dev/null; then
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] 👤 Creating user '$WP_USER'..."
    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --user_pass="$WP_PASSWORD" \
        --role="author" \
        --path="$WORDPRESS_PATH" \
        --allow-root
else
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] ✔️ User '$WP_USER' already exists."
fi

# 5️⃣ Permisos
chown -R www-data:www-data "$WORDPRESS_PATH"
chmod -R 755 "$WORDPRESS_PATH"

echo "[$(date '+%Y-%m-%d %H:%M:%S')] 🏁 Ready! Launching PHP-FPM..."

exec php-fpm81 -F