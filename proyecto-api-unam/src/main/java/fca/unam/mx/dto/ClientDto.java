package fca.unam.mx.dto;

import org.jdbi.v3.core.mapper.reflect.ColumnName;

public class ClientDto {
    private Long id;
    private String name;
    private String father_last_name;
    private String mother_last_name;
    private String rfc;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @ColumnName("nombre")
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @ColumnName("apellido_paterno")
    public String getFatherLastName() {
        return father_last_name;
    }

    public void setFatherLastName(String father_last_name) {
        this.father_last_name = father_last_name;
    }

    @ColumnName("apellido_materno")
    public String getMotherLastName() {
        return mother_last_name;
    }

    public void setMotherLastName(String mother_last_name) {
        this.mother_last_name = mother_last_name;
    }

    @ColumnName("RFC")
    public String getRfc() {
        return rfc;
    }

    public void setRfc(String rfc) {
        this.rfc = rfc;
    }

}
