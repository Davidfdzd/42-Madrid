####### VARIABLES #######
NAME        = Inception
USER        = dfernan3
COMPOSE     = docker compose
COMPOSE_FILE = srcs/docker-compose.yml

# Rutas de datos
DATA_PATH    = /home/$(USER)/data
MARIADB_DIR = $(DATA_PATH)/mariadb
WORDPRESS_DIR = $(DATA_PATH)/wordpress

# Certificados
CERT_DIR    = srcs/requirements/nginx/certs
CERT_KEY    = $(CERT_DIR)/server.key
CERT_CRT    = $(CERT_DIR)/server.crt

####### COLORES (Estilo Cyberpunk) #######
CYAN        = \033[38;5;51m
PURPLE      = \033[38;5;141m
PINK        = \033[38;5;198m
GREEN       = \033[38;5;82m
RED         = \033[38;5;196m
YELLOW      = \033[38;5;226m
RESET       = \033[0m
BOLD        = \033[1m

####### COMANDOS MÁGICOS #######

# Spinner de carga mejorado
define show_spinner
	@printf "$(PURPLE)[$(RESET)$(CYAN)··$(RESET)$(PURPLE)]$(RESET) $(1)... "
	@sleep 0.5
	@printf "\r"
endef

# Notificación de éxito
define success_msg
	@echo "$(GREEN)$(BOLD)[✔]$(RESET) $(GREEN)$(1)$(RESET)"
endef

####### REGLAS PRINCIPALES #######

.PHONY: all up down fclean re clean_data dirs ssl logs

all: up

# Levanta el sistema completo
up: ascii dirs ssl
	$(call show_spinner,Inyectando contenedores en la red)
	@$(COMPOSE) -f $(COMPOSE_FILE) up --build -d
	$(call success_msg,Sistema Inception desplegado para $(USER))
	@echo "$(PURPLE)-------------------------------------------------------$(RESET)"
	@echo "$(CYAN)Acceso: $(BOLD)https://$(USER).42.fr$(RESET)"
	@echo "$(PURPLE)-------------------------------------------------------$(RESET)"

# Apaga los motores
down:
	@echo "$(YELLOW)Deteniendo motores de $(NAME)...$(RESET)"
	@$(COMPOSE) $(COMPOSE_FILE) down
	$(call success_msg,Contenedores detenidos correctamente)

fclean: down
	@echo "$(RED)Iniciando protocolo de desintegración total...$(RESET)"
	@$(COMPOSE) -f $(COMPOSE_FILE) down --volumes --remove-orphans
	@docker system prune -af
	@sudo rm -rf $(DATA_PATH)
	$(call success_msg,Todo rastro de $(USER) ha sido eliminado)

re: fclean all

####### UTILIDADES #######

# Crea las carpetas de volúmenes si no existen
dirs:
	@mkdir -p $(MARIADB_DIR)
	@mkdir -p $(WORDPRESS_DIR)
	$(call success_msg,Volúmenes listos en /home/$(USER)/data)

# Genera certificados si faltan
ssl:
	@if [ ! -f $(CERT_KEY) ] || [ ! -f $(CERT_CRT) ]; then \
		@echo "$(YELLOW)Generando credenciales SSL para $(USER)...$(RESET)"; \
		mkdir -p $(CERT_DIR); \
		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
			-keyout $(CERT_KEY) -out $(CERT_CRT) \
			-subj "/C=ES/ST=Malaga/L=Malaga/O=42/OU=$(USER)/CN=$(USER).42.fr"; \
		$(call success_msg,Certificados SSL creados); \
	fi

# Arte ASCII Personalizado
ascii:
	@clear
	@echo "$(PURPLE)██╗███╗   ██╗ █████╗  ██████╗ ███████╗███████╗$(RESET)"
	@echo "$(CYAN)██║████╗  ██║██╔══██╗██╔════╝ ██╔════╝██╔════╝$(RESET)"
	@echo "$(PINK)██║██╔██╗ ██║███████║██║  ███╗█████╗  ███████╗$(RESET)"
	@echo "$(GREEN)██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ╚════██║$(RESET)"
	@echo "$(YELLOW)██║██║ ╚████║██║  ██║╚██████╔╝███████╗███████║$(RESET)"
	@echo "$(PURPLE)╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝$(RESET)"
	@echo "$(BOLD)$(PINK) >>>>   INFRAESTRUCTURA DE: $(USER) – INCEPTION 42   <<<< $(RESET)"
	@echo ""

# Logs en tiempo real
logs:
	@$(COMPOSE) -f $(COMPOSE_FILE) logs -f
