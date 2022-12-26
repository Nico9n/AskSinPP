//- -----------------------------------------------------------------------------------------------------------------------
// AskSin driver implementation
// 2013-08-03 <trilu@gmx.de> Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------
//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2016-10-31 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
// 2019-03-31 stan23 Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------
//- -----------------------------------------------------------------------------------------------------------------------
//- AskSin SX1276 functions -----------------------------------------------------------------------------------------------
//- based on
//- -----------------------------------------------------------------------------------------------------------------------

/*
  TODO:


*/

#ifndef _SX1276_H
#define _SX1276_H

namespace as
{

  // SX1276 registers

  template <class SPIType, uint8_t PWRPIN, uint8_t IRQPIN>
  class SX1276
  {
  protected:
    SPIType spi;
    uint8_t rss; // signal strength

#ifdef USE_OTA_BOOTLOADER_FREQUENCY
    DPRINTLN("ERROR: USE_OTA_BOOTLOADER_FREQUENCY is not implemented for SX1276!");
#endif

  public:
    SX1276() : rss(0)
#ifdef USE_OTA_BOOTLOADER_FREQUENCY
               ,
               DPRINTLN("ERROR: USE_OTA_BOOTLOADER_FREQUENCY is not implemented for SX1276!");
#endif
    {
    }

    /// @brief Gibt zurück, ob bei einem Interupt auf die steigende oder fallende Flanke getriggert werden soll.
    /// @param return RISING, es muss auf die steigende Flanke getriggert werden, da der Interrupt Pin bis zum auslesen des FIFO auf high bleibt.
    uint8_t interruptMode()
    {
      return RISING;
    };

    void setIdle()
    {
    }

    /// @brief
    /// @param p_flush Wenn true wird flushrx() aufgerufen.
    void wakeup(bool p_flush)
    {
    }

    /// @brief
    /// @returns immer 1
    uint8_t reset()
    {
      uint8_t ret = 1;

      return ret;
    }

    /// @brief Liest einen Wert aus dem Register
    /// @param p_reg Register Adresse
    /// @returns Register Wert
    uint8_t readReg(uint8_t p_reg)
    {
      return spi.readReg(p_reg, 0);
    }

    void writeBurstReg(uint8_t p_reg, uint8_t *p_buf, uint8_t p_len)
    {
      // TODO
    }

    void readBurst(uint8_t *p_buf, uint8_t p_regAddr, uint8_t p_len)
    {
      // TODO
    }

    /// @brief Schreibt einen Wert in das Register.
    /// Im Gegensatz zu writeReg wird immer der komplette Wert geschrieben und hinterher nicht geprüft.
    /// @param p_reg Register Adresse
    /// @param p_value Register Wert
    void writeCmd(uint8_t p_reg, uint8_t p_value)
    {
      uint8_t reg = p_reg | (1 << 7);
      spi.writeReg(reg, p_value);
      _delay_ms(10);
    }

    /// @brief
    /// @param p_reg Register Adresse
    /// @param p_value Register Wert
    /// @param p_msb Ab diesem Bit wird eine Änderung berücksichtigt
    /// @param p_lsb Bis zu diesem Bit wird eine Änderung berücksichtigt
    /// @param p_retries Anzahl der Versuche, falls das Schreiben fehlschlägt.
    /// @return true bei Erfolg
    bool writeReg(uint8_t p_reg, uint8_t p_value, uint8_t p_msb = 7, uint8_t p_lsb = 0, uint8_t p_retries = 3)
    {
      return true;
    }

    bool init()
    {
      bool initOK = true;
      return initOK;
    }

    bool initReg(uint8_t p_regAddr, uint8_t p_val, uint8_t p_retries = 3)
    {
      // DPRINTLN(__func__);
      bool initResult = writeReg(p_regAddr, p_val, 7, 0, p_retries);
      return initResult;
    }

    void tuneFreq(__attribute__((unused)) uint8_t freq2, __attribute__((unused)) uint8_t freq1, __attribute__((unused)) uint8_t freq0)
    {
      // SX1276 does not have problems with wrong oscillator capacitors on cheap modules
    }

    uint8_t rssi() const
    {
      return rss;
    }

    void flushrx()
    {
    }

    bool detectBurst()
    {
      // TODO
      return true;
    }

    void pollRSSI()
    {
    }

  protected:
    void calculateRSSI(uint8_t p_rsshex)
    {
    }

    uint8_t sndData(uint8_t *p_buf, uint8_t p_size, uint8_t p_burst)
    {
      return true;
    }

    uint8_t rcvData(uint8_t *p_buf, uint8_t p_size)
    {

      return 1; // return number of byte in buffer
    }
  };
}

#endif
