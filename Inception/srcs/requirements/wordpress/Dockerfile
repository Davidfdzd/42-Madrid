FROM alpine:3.18

RUN apk update && apk add --no-cache \
    bash \
    mariadb-client \
    libc6-compat \
    php81 \
    php81-fpm \
    php81-cli \
    php81-phar \
    php81-mysqli \
    php81-curl \
    php81-json \
    php81-xml \
    php81-mbstring \
    php81-session \
    php81-zip \
    php81-gd \
    php81-opcache \
    wget \
    curl \
    unzip \
    tar \
    less

RUN ln -sf /usr/bin/php81 /usr/bin/php

RUN addgroup -S www-data || true && adduser -S -G www-data www-data || true

RUN mkdir -p /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress

WORKDIR /var/www

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz \
    && rm latest.tar.gz

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

RUN sed -i 's|listen = 127.0.0.1:9000|listen = 0.0.0.0:9000|' /etc/php81/php-fpm.d/www.conf

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

VOLUME ["/var/www/wordpress"]

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]