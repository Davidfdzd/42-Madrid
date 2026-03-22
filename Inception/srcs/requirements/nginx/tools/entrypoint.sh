#!/bin/sh

until getent hosts wordpress; do
    echo "Esperando a que el host worldpres este disponible..."
    sleep 2;
done

exec nginx -g "daemon off;" #para que no se apague el contendor