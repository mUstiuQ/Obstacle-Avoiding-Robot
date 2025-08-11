# Obstacle-Avoiding-Robot
An **autonomous vehicle** equipped with ultrasonic sensors and motor control, capable of detecting and avoiding obstacles in real time for smooth navigation.

#  Features
- **Ultrasonic distance measurement** using HC-SR04 sensors.
- **Autonomous movement** with L298N motor driver and DC motors.
- **Real-time obstacle detection** and avoidance.
- Adjustable speed control via PWM.
- Modular code structure for easy customization.

---

## Components Used
| Component           | Quantity | Description                               |
|---------------------|----------|-------------------------------------------|
| Arduino Nano        | 1        | Main microcontroller                      |
| HC-SR04 Sensor      | 1 or 3   | Ultrasonic distance sensors               |
| L298N Motor Driver  | 1        | Controls DC motors                        |
| DC Motors + Wheels  | 2        | Drive mechanism                           |
| Servo Motor         | 1        | Rotates ultrasonic sensor (optional)      |
| Power Supply        | 1        | Battery pack or power bank                |

---

##  How It Works
1. **Ultrasonic sensor** measures the distance to the nearest object.
2. **Arduino** processes the data and decides the next move.
3. If an obstacle is detected within a threshold distance:
   - Robot stops
   - Rotates sensor (optional) to scan the environment
   - Chooses the safest direction
4. **Motors** execute movement to avoid collision.

---

### Hardware Setup
- Connect the **HC-SR04** to Arduino pins (Trigger, Echo).
- Wire **DC motors** to L298N driver and connect ENA/ENB for speed control.
- Connect **servo motor** (if used) to Arduino PWM pin.
- Power the system with a battery pack (6x AA or Li-ion).
- To easily view look at the schematic image.


## License
This project is licensed under the MIT License – feel free to use and modify it.



